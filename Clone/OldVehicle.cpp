//
// Created by davide on 02/07/21.
//

#include "OldVehicle.h"


OldVehicle::OldVehicle(int X, int Y, float ac, float maxVel, int HP, int le, int wi,
                 bool col, std::string nat) : posX(X), posY(Y), acceleration(ac), maxSpeed(maxVel), hp(HP),
                                              length(le), collision(col), width(wi), nationality(nat), maxHP(HP),
                                              currentSpeed(0) {

    pos = sf::Vector2f(X, Y);
    sprite.setPosition(pos);

}

void OldVehicle::attack(std::_List_iterator<std::unique_ptr<Vehicle>> target) {

}

float OldVehicle::calculateDistance(sf::Vector2f &first, sf::Vector2f &second) {    //calcola la distanza tra due punti
    return sqrt(pow(first.y - second.y, 2) + pow(first.x - second.x, 2));
}

void OldVehicle::update(bool isDead) {

}


bool OldVehicle::setUpSprite(std::string textureName) {  //Carica la sprite

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


float OldVehicle::getAcceleration() const {
    return acceleration;
}

const float OldVehicle::getMaxSpeed() const {
    return maxSpeed;
}

double OldVehicle::getHp() const {
    return hp;
}

int OldVehicle::getLength() const {
    return length;
}

int OldVehicle::getWidth() const {
    return width;
}

bool OldVehicle::isCollision() const {
    return collision;
}

sf::Sprite &OldVehicle::getSprite() {
    return sprite;
}

const sf::Vector2f &OldVehicle::getPos() const {
    return pos;
}

const std::string &OldVehicle::getNationality() const {
    return nationality;
}

void OldVehicle::setCollision(bool collision) {
    OldVehicle::collision = collision;
}

void OldVehicle::updatePlanes(sf::Vector2f &vel, double mx) {
}

void OldVehicle::setCurrentSpeed(float currentSpeed) {
    Vehicle::currentSpeed = currentSpeed;
}

void OldVehicle::setDeath(bool death) {
    Vehicle::death = death;
}

const double OldVehicle::getMaxHp() const {
    return maxHP;
}

bool OldVehicle::isDeath() const {
    return death;
}

float OldVehicle::rotate(float mx, float rotatingInPlaceMult) {  //rutoa la sprite della nave soltanto
    float deltaMx = 0;
    if (abs(sprite.getRotation() - mx) >=
        1.5) {  // Verifica che la rotazione da effettuare sia sufficiebntemente grande (risolve un glitch grafico)
        if (((mx - sprite.getRotation()) <= 180) && (mx - sprite.getRotation()) >
                                                    0) {  //Analizza le casistiche e di conseguenza ruota incrementando/decrementando l'angolo
            deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 1000;
            sprite.rotate(deltaMx);
        } else if (sprite.getRotation() > 180 && mx < 180) {
            deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 1000;
            sprite.rotate(deltaMx);
        } else {
            deltaMx = -currentSpeed * acceleration * rotatingInPlaceMult / 1000;
            sprite.rotate(deltaMx);
        }
    }
    return deltaMx;
}

float OldVehicle::calculateMx(float dx,
                           float dy) {  //Calcola l'angolo da raggiungere (già tradotto secondo la logica della SFML)
    float mx = 0;
    mx = 90 + atan2(dy, dx) * 180 / M_PI;

    if (mx < 0) {
        mx = 360 + mx;
    }
    return mx;
}

void OldVehicle::move(sf::Vector2f coordinates, double dt) {
    if (!death) {   //verifica morte e incagliamento
        double mx;
        double dy = coordinates.y - sprite.getPosition().y;
        double dx = coordinates.x - sprite.getPosition().x;
        float rotatingInPlaceMult = 1;
        double deltaMx = 0;

        mx = calculateMx(dx, dy);
        if (currentSpeed <= maxSpeed * 2) {
            currentSpeed = currentSpeed + acceleration / 100 * 2;
        }
        sf::Vector2f vel;

        if (abs(sprite.getRotation() - mx) >=
            25) {  //Se la rotazione da effettuare è elevata allora ruota più velocemente
            rotatingInPlaceMult = 3;
            if (currentSpeed > maxSpeed / 4)
                currentSpeed = currentSpeed - acceleration / 100;
        }
        if ((abs(coordinates.x - sprite.getPosition().x) < sprite.getTextureRect().height / 2 &&
             abs(coordinates.y - sprite.getPosition().y) < sprite.getTextureRect().height /
                                                           2)) {   //Se il punto da raggiungere è vicino la nave avanza lentamente
            if (currentSpeed > acceleration / 100) {
                currentSpeed = currentSpeed - acceleration / 100;
            }
        }
        vel.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * dt * acceleration / 10;
        vel.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * dt * acceleration / 10;
        sprite.setPosition(sprite.getPosition() + vel);
        deltaMx = rotate(mx, rotatingInPlaceMult);

    }

}

void OldVehicle::planeAttack(std::_List_iterator<std::unique_ptr<Vehicle>> target, float dt) {


}

void OldVehicle::moveAndAttack(std::_List_iterator<std::unique_ptr<Vehicle>> target, float dt) {
    move(target->get()->getSprite().getPosition(), dt);
    if (abs(target->get()->getSprite().getPosition().x - sprite.getPosition().x) < 90 &&
        abs(target->get()->getSprite().getPosition().y - sprite.getPosition().y) < 90) {
        planeAttack(target, dt);
    }
}



