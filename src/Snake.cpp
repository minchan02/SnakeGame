#include "Snake.h"

Snake::Snake(int width, int height){
    dir = LEFT; // 처음엔 LEFT로 
    // 초기 Snake의 위치는 가운데
    body.push_back(make_pair(height/2, width/2-1));
    body.push_back(make_pair(height/2, width/2));
    body.push_back(make_pair(height/2, width/2+1));
}

void Snake::moveLeft(){
    auto head = body.front();
    head.second--;
    body.push_front(head);
    body.pop_back();
}

void Snake::moveRight(){
    auto head = body.front();
    head.second++;
    body.push_front(head);
    body.pop_back();
}

void Snake::moveUp(){
    auto head = body.front();
    head.first--;
    body.push_front(head);
    body.pop_back();
}

void Snake::moveDown(){
    auto head = body.front();
    head.first++;
    body.push_front(head);
    body.pop_back();
}

int Snake::getLength(){
    return body.size();
}