//
// Created by davide on 02/07/21.
//

#include "Vehicle.h"
Vehicle::Vehicle(int X, int Y, float ac, float maxVel, int HP, int le, int wi,
                 bool col, std::string nat) : posX(X), posY(Y), acceleration(ac), maxSpeed(maxVel), hp(HP),
                                              length(le), collision(col), width(wi), nationality(nat), maxHP(HP),
                                              currentSpeed(0) {

    pos = sf::Vector2f(X, Y);
    sprite.setPosition(pos);

}

void Vehicle::attack(std::_List_iterator<std::unique_ptr<Vehicle>> target) {

}

float Vehicle::calculateDistance(sf::Vector2f &first, sf::Vector2f &second) {    //calcola la distanza tra due punti
    return sqrt(pow(first.y - second.y, 2) + pow(first.x - second.x, 2));
}

void Vehicle::update(bool isDead) {

}


bool Vehicle::setUpSprite(std::string textureName) {  //Carica la sprite

    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {   //Permette il corretto caricamento anche nel caso in cui si avviino i test
        currentDir.erase(found);
        currentDir.pop_back();
    }
    textureName = currentDir + "/../Res/" + nationality + "/" + textureName + ".png";
    if (!Collision::CreateTextureAndBitmask(texture, textureName)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, length));
    return true;
}



float Vehicle::getAcceleration() const {
    return acceleration;
}

const float Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

double Vehicle::getHp() const {
    return hp;
}

int Vehicle::getLength() const {
    return length;
}

int Vehicle::getWidth() const {
    return width;
}

bool Vehicle::isCollision() const {
    return collision;
}

sf::Sprite &Vehicle::getSprite() {
    return sprite;
}

const sf::Vector2f &Vehicle::getPos() const {
    return pos;
}

const std::string &Vehicle::getNationality() const {
    return nationality;
}

void Vehicle::setCollision(bool collision) {
    Vehicle::collision = collision;
}

void Vehicle::updatePlanes(sf::Vector2f &vel, double mx) {
}

void Vehicle::setCurrentSpeed(float currentSpeed) {
    Vehicle::currentSpeed = currentSpeed;
}

void Vehicle::setDeath(bool death) {
    Vehicle::death = death;
}

const double Vehicle::getMaxHp() const {
    return maxHP;
}

bool Vehicle::isDeath() const {
    return death;
}

float Vehicle::rotate(float mx, float rotatingInPlaceMult) {  //rutoa la sprite della nave soltanto
    float deltaMx = 0;
    if (abs(sprite.getRotation() - mx) >=
        1.5) {  // Verifica che la rotazione da effettuare sia sufficiebntemente grande (risolve un glitch grafico)
        if (((mx - sprite.getRotation()) <= 180) && (mx - sprite.getRotation()) >
                                                    0) {  //Analizza le casistiche e di conseguenza ruota incrementando/decrementando l'angolo
            deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 4000;
            sprite.rotate(deltaMx);
        } else if (sprite.getRotation() > 180 && mx < 180) {
            deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 4000;
            sprite.rotate(deltaMx);
        } else {
            deltaMx = -currentSpeed * acceleration * rotatingInPlaceMult / 4000;
            sprite.rotate(deltaMx);
        }
    }
    return deltaMx;
}

float Vehicle::calculateMx(float dx,
                           float dy) {  //Calcola l'angolo da raggiungere (già tradotto secondo la logica della SFML)
    float mx = 0;
    mx = 90 + atan2(dy, dx) * 180 / M_PI;

    if (mx < 0) {
        mx = 360 + mx;
    }
    return mx;
}

void Vehicle::move(sf::Vector2<double> coordinates, double dt) {
    if (!death) {   //verifica morte
        double mx;
        double dy = coordinates.y - sprite.getPosition().y;
        double dx = coordinates.x - sprite.getPosition().x;
        float rotatingInPlaceMult = 1;
        

        mx = calculateMx(dx, dy);
        //FIXME togli il *10
        if (currentSpeed <= maxSpeed * 10) {
            currentSpeed = currentSpeed + acceleration / 100 * 10;
        }
        sf::Vector2f vel;
       //controlla se l'aereo ha raggiunto la destinazine
            if (abs(sprite.getRotation() - mx) >=
                25) {  //Se la rotazione da effettuare è elevata allora ruota più velocemente
                rotatingInPlaceMult = 3;
                if (currentSpeed > maxSpeed / 4)
                    currentSpeed = currentSpeed - acceleration / 100;
            }
            if ((abs(coordinates.x - sprite.getPosition().x) < sprite.getTextureRect().height / 2 &&
                 abs(coordinates.y - sprite.getPosition().y) < sprite.getTextureRect().height /
                                                               2)) {   //Se il punto da raggiungere è vicino l'aereo avanza lentamente
                if (currentSpeed > acceleration / 100) {
                    currentSpeed = currentSpeed - acceleration / 100;
                }
            }
            vel.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * dt * acceleration / 10;
            vel.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * dt * acceleration / 10;
            sprite.setPosition(sprite.getPosition() + vel);
            rotate(mx, rotatingInPlaceMult);


    }

}

