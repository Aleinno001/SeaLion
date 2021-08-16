#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "GameWorld.h"

enum class windowMode {
    Windowed,
    Fullscreen
};

std::vector<Fleet> alliedDummyFleet() {
    std::vector<Fleet> fleet;
    Fleet alliedFleet;

    alliedFleet.name = ModelType::DaVinci;
    alliedFleet.num = 1;
    alliedFleet.type = ShipType::Submarine;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::Papa;
    alliedFleet.num = 1;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::Impavido;
    alliedFleet.num = 1;
    alliedFleet.type = ShipType::Destroyer;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::PaoloEmilio;
    alliedFleet.num = 1;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::Leone;
    alliedFleet.num = 1;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::AlbertoDiGiussano;
    alliedFleet.num = 1;
    alliedFleet.type = ShipType::Cruiser;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::Gorizia;
    alliedFleet.num = 1;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::Trento;
    alliedFleet.num = 1;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::GiuseppeGaribaldi;
    alliedFleet.num = 1;
    alliedFleet.type = ShipType::AircraftCarrier;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::Cavour;
    alliedFleet.num = 1;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::ImperatoreAugusto;
    alliedFleet.num = 2;
    alliedFleet.type = ShipType::Battleship;

    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::MichelangeloBuonarroti;
    alliedFleet.num = 1;


    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::AndreaDoria;
    alliedFleet.num = 1;


    fleet.emplace_back(alliedFleet);

    alliedFleet.name = ModelType::VittorioVeneto;
    alliedFleet.num = 1;


    fleet.emplace_back(alliedFleet);


    return fleet;


}

typedef struct iteratorPositions{
    std::_List_iterator<std::unique_ptr<WarShip>> it;
    sf::Vector2i pos;
};



void update( std::list<iteratorPositions> lst){
    if(!lst.empty()){
        for (auto iter = lst.begin(); iter != lst.end();) {
            if((iter->it->get()->getSprite().getPosition().x)==iter->pos.x && iter->it->get()->getSprite().getPosition().y==iter->pos.y){
                iter=lst.erase(iter);
                std::cerr<<"cancella"<<std::endl;
            }else{
                iter->it->get()->move(iter->pos);
                ++iter;
            }
        }
    }
}

int main() {
    std::vector<Fleet> fleet = alliedDummyFleet();


    sf::Vector2i boundaries(1920, 1080);
    int a, b, c, d, e;
    int width, height, tileDim;
    windowMode videoMode = windowMode::Windowed;
    a = 3;
    b = 3;
    c = 3;
    d = 3;
    e = 2;

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;

    sf::RenderWindow window;
    auto desktop = sf::VideoMode::getDesktopMode();
    width = desktop.width;
    height = desktop.height;
    tileDim = 30;  //FIXME adattabile a tutte le risoluzioni
    window.create(sf::VideoMode(width, height), "SeaLion", sf::Style::Default, settings);
    window.setPosition(sf::Vector2i(0, 0));

    GameWorld gameWorld = GameWorld(a, b, c, d, e, fleet, FactionType::Italy, FactionType::Italy, 8, boundaries, width,
                                    height, tileDim);
    int shipCounter = 0;
    bool found = false;
    auto itSecondClick = gameWorld.getAlliedFleet().begin();
    //std::list<std::_List_iterator<std::unique_ptr<WarShip>>> movingShips;
    //std::multimap< std::_List_iterator<std::unique_ptr<WarShip>>,sf::Vector2i,shipComparator> movingShips;
    std::list<iteratorPositions> lst;
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11 &&
                       videoMode == windowMode::Fullscreen) {
                window.create(sf::VideoMode(width, height), "OpenGL", sf::Style::Default, settings);
                videoMode = windowMode::Windowed;
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11 &&
                       videoMode == windowMode::Windowed) {
                window.create(sf::VideoMode(width, height), "OpenGL", sf::Style::Fullscreen, settings);
                videoMode = windowMode::Fullscreen;
            }else if(event.type == sf::Event::MouseButtonPressed){
                switch(event.key.code)
                {
                    case sf::Mouse::Left:{

                        sf::Vector2i coords(event.mouseButton.x,event.mouseButton.y);

                            if(found == false){
                                itSecondClick = gameWorld.getAlliedFleet().begin();
                                auto translated_pos = window.mapPixelToCoords(coords);

                                for (auto it = gameWorld.getAlliedFleet().begin(); it != gameWorld.getAlliedFleet().end() && found == false; ++it,shipCounter++) {
                                    std::cerr<<"Cerco nave"<<std::endl;

                                    if(it->get()->getSprite().getGlobalBounds().contains(translated_pos)){


                                        found=true;
                                        std::cerr<<found<<" "<<it->get()<<std::endl;


                                    }

                                }
                                if(found==false){
                                    shipCounter=0;
                                }
                            }else{
                                int miniCounter = 0;

                                while(miniCounter<shipCounter-1){
                                    ++itSecondClick;
                                    miniCounter++;
                                }
                                /*FIXME Controllare che la nave selezionata NON sia stata distrutta*/
                                /*TODO Da gestire l'evento di selezionamento poi la nave viene distrutta e quindi deselezionare evitando di far effettuare il secondo click di spostamento */
                                std::cerr << itSecondClick->get()->getArmour()<< " " << std::endl;
                                /*
                                if(!(movingShips.find(itSecondClick)==movingShips.end())){
                                    auto it=movingShips.find(itSecondClick);
                                    it->second=coords;
                                }else{
                                    movingShips.insert(std::make_pair(itSecondClick,coords));
                                }
                                */
                                iteratorPositions itPos;
                                itPos.it = itSecondClick;
                                itPos.pos = coords;
                                lst.push_back(itPos);
                                shipCounter=0;
                                found=false;
                            }





                    }break;

                    case sf::Mouse::Right:

                        break;
                }
            }else if(event.type==sf::Event::MouseWheelMoved){

            }else if(event.type==sf::Event::MouseMoved){

            }
        }

        window.clear();
        for (int i = 0; i < (gameWorld.getMapHeight() / 30); i++) {
            for (int j = 0; j < (gameWorld.getMapWidth() / 30); j++) {
                window.draw(gameWorld.getTiles()[i][j]->getSprite());

            }

        }

        for (auto it = gameWorld.getEnemyFleet().begin(); it != gameWorld.getEnemyFleet().end(); ++it) {
            window.draw(it->get()->getSprite());
            //auto itArsenal = it->get()->getArsenalList().begin();



            //for(auto itArsenal = it->get()->getArsenalList().begin();itArsenal->get()->getTextureName()!="AntiAircraft" && itArsenal->get()->getTextureName()!="TorpedoTube";++itArsenal){
            //window.draw(itArsenal->get()->getSprite());
            //}

            for (auto const &itArsenal : it->get()->getArsenalList()) {

                if (itArsenal->getTextureName() != "AntiAircraft" && itArsenal->getTextureName() != "TorpedoTube") {
                    window.draw(itArsenal->getSprite());
                }
            }
        }

        for (auto it = gameWorld.getAlliedFleet().begin(); it != gameWorld.getAlliedFleet().end(); ++it) {
            window.draw(it->get()->getSprite());

            for (auto const &itArsenal : it->get()->getArsenalList()) {

                if (itArsenal->getTextureName() != "AntiAircraft" && itArsenal->getTextureName() != "TorpedoTube") {
                    window.draw(itArsenal->getSprite());
                }
            }

        }

        update(lst);

        window.display();
    }
    return 0;
}



