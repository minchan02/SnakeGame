#include "ScoreBoard.h"
ScoreBoard::ScoreBoard(){
  currentMission = mission.getMission(0);
  setlocale(LC_ALL, "");
  LENGTH = ("LEGNTH | " + to_string(currentMission[0]));
  GROWTH = ("GROWTH | " + to_string(currentMission[1]));
  POISON = ("POISON | " + to_string(currentMission[2]));
  GATE   = ("  GATE | " + to_string(currentMission[3]));
  
  currentStage = 0;
  
  lengthScore = 3;
  growthScore = 0;
  poisonScore = 0;
  gateScore = 0; 
  
  
  lengthProgressBar = L"□ □ □ □ □";
  growthProgressBar = L"□ □ □ □ □";
  poisonProgressBar = L"□ □ □ □ □";
  gateProgressBar = L"□ □ □ □ □";
  
  lengthCleared = false;
  growthCleared = false;
  poisonCleared = false;
  gateCleared = false;
  
  
  scoreBoard = {
  		{2,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  		{2,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		};
}
void ScoreBoard::drawBoard(){
  currentStage = getCurrentStage();
  currentMission = mission.getMission(currentStage);
  string current_str = to_string(currentMission[0]) + to_string(currentMission[1]);
  mvprintw(23, 4, current_str.c_str());
  
  for (int y = 0; y<BOARD_H; ++y){
    for (int x=0; x<BOARD_W; ++x){
      if(scoreBoard[y][x] == 1){
        mvaddnwstr(y, x*2+MAP_W, &boardWall, 1);
      }
      if(scoreBoard[y][x] == 2){
        mvaddnwstr(y, x*2+MAP_W, &partition, 1);
      }
    }
  }
  
  //ScoreBoard Template
  mvaddstr(0, 6+MAP_W, "====== MISSION =======");
  LENGTH = ("LEGNTH | " + to_string(currentMission[0]));
  GROWTH = ("GROWTH | " + to_string(currentMission[1]));
  POISON = ("POISON | " + to_string(currentMission[2]));
  GATE   = ("  GATE | " + to_string(currentMission[3]));
  
  mvaddstr(2, CHAR_X, LENGTH.c_str());
  mvaddstr(4, CHAR_X, GROWTH.c_str());
  mvaddstr(6, CHAR_X, POISON.c_str());
  mvaddstr(8, CHAR_X, GATE.c_str());
  
  
  mvaddstr(10, 6+MAP_W, "====== PROGRESS ======");
  mvaddstr(12, CHAR_X, "LEGNTH  ");
  mvaddstr(14, CHAR_X, "GROWTH  ");
  mvaddstr(16, CHAR_X, "POISON  ");
  mvaddstr(18, CHAR_X, "  GATE  ");
}   
void ScoreBoard::printScore(){
  currentStage = stageManager.getCurrentStage();
  currentMission = mission.getMission(currentStage);
  currentScore = stageManager.getScore();
  
  lengthScore = currentScore[0];
  growthScore = currentScore[1];
  poisonScore = currentScore[2];
  gateScore = currentScore[3];
  

  //mvaddstr(12, CHAR_X + 9, to_string(lengthScore).c_str()); 
  //mvaddstr(14, CHAR_X + 9, to_string(growthScore).c_str()); 
  //mvaddstr(16, CHAR_X + 9, to_string(poisonScore).c_str()); 
  //mvaddstr(18, CHAR_X + 9, to_string(gateScore).c_str()); 
  
  switch (currentStage){
    //Stage 1
    case 0:
      if(lengthScore == 3) lengthProgressBar = L"■ ■ ■ □ □";
      else if(lengthScore == 4) lengthProgressBar = L"■ ■ ■ ■ □";
      else if(lengthScore >= 5) lengthProgressBar = L"■ ■ ■ ■ ■";
    
      if(growthScore == 0) growthProgressBar = L"□ □ □ □ □";
      else if(growthScore == 1) growthProgressBar = L"■ □ □ □ □";
      else if(growthScore == 2) growthProgressBar = L"■ ■ ■ □ □";
      else if(growthScore >= 3) growthProgressBar = L"■ ■ ■ ■ ■";
    
      if(poisonScore == 0) poisonProgressBar = L"□ □ □ □ □"; 
      else if(poisonScore >=1) poisonProgressBar = L"■ ■ ■ ■ ■";
          
      if(gateScore == 0) gateProgressBar = L"□ □ □ □ □"; 
      else if(gateScore >=1) gateProgressBar = L"■ ■ ■ ■ ■";
      break;
    //Stage 2
    case 1:
      if(lengthScore == 3) lengthProgressBar = L"■ □ □ □ □";
      else if(lengthScore == 4) lengthProgressBar = L"■ ■ □ □ □";
      else if(lengthScore == 5) lengthProgressBar = L"■ ■ ■ □ □";
      else if(lengthScore == 6) lengthProgressBar = L"■ ■ ■ ■ □";
      else if(lengthScore >= 7) lengthProgressBar = L"■ ■ ■ ■ ■";
      
    
      if(growthScore == 0) growthProgressBar = L"□ □ □ □ □";
      else if(growthScore == 1) growthProgressBar = L"■ □ □ □ □";
      else if(growthScore == 2) growthProgressBar = L"■ ■ □ □ □";
      else if(growthScore == 3) growthProgressBar = L"■ ■ ■ □ □";
      else if(growthScore == 4) growthProgressBar = L"■ ■ ■ ■ □";
      else if(growthScore == 5) growthProgressBar = L"■ ■ ■ ■ ■";
    
      if(poisonScore == 0) poisonProgressBar = L"□ □ □ □ □"; 
      else if(poisonScore ==1) poisonProgressBar = L"■ ■ ■ □ □";
      else if(poisonScore >=2) poisonProgressBar = L"■ ■ ■ ■ ■";
      
      if(gateScore == 0) gateProgressBar = L"□ □ □ □ □"; 
      else if(gateScore ==1) gateProgressBar = L"■ ■ ■ □ □";
      else if(gateScore >=2) gateProgressBar = L"■ ■ ■ ■ ■";
      break;
    
    //Stage 3
    case 2:
      if(lengthScore == 3) lengthProgressBar = L"□ □ □ □ □";
      else if(lengthScore == 4 || lengthScore == 5) lengthProgressBar = L"■ □ □ □ □";
      else if(lengthScore == 6) lengthProgressBar = L"■ ■ □ □ □";
      else if(lengthScore == 7) lengthProgressBar = L"■ ■ ■ □ □";
      else if(lengthScore == 8) lengthProgressBar = L"■ ■ ■ ■ □";
      else if(lengthScore >= 9) lengthProgressBar = L"■ ■ ■ ■ ■";
      
      if(growthScore == 0) growthProgressBar = L"□ □ □ □ □";
      else if(growthScore >= 1 && growthScore < 3) growthProgressBar = L"■ □ □ □ □";
      else if(growthScore >= 3 && growthScore < 5) growthProgressBar = L"■ ■ □ □ □";
      else if(growthScore == 5) growthProgressBar = L"■ ■ ■ □ □";
      else if(growthScore == 6) growthProgressBar = L"■ ■ ■ ■ □";
      else if(growthScore >= 7) growthProgressBar = L"■ ■ ■ ■ ■";
    
      if(poisonScore == 0) poisonProgressBar = L"□ □ □ □ □"; 
      else if(poisonScore ==1) poisonProgressBar = L"■ □ □ □ □";
      else if(poisonScore ==2) poisonProgressBar = L"■ ■ ■ □ □";
      else if(poisonScore >=3) poisonProgressBar = L"■ ■ ■ ■ ■";
      
      if(gateScore == 0) gateProgressBar = L"□ □ □ □ □"; 
      else if(gateScore ==1) gateProgressBar = L"■ □ □ □ □";
      else if(gateScore ==2) gateProgressBar = L"■ ■ ■ □ □";
      else if(gateScore >=3) gateProgressBar = L"■ ■ ■ ■ ■";
      break;
      
    //Stage 4
    case 3:
      if(lengthScore == 3) lengthProgressBar = L"□ □ □ □ □";
      else if(lengthScore == 4 || lengthScore == 5) lengthProgressBar = L"■ □ □ □ □";
      else if(lengthScore >= 6 && lengthScore < 8) lengthProgressBar = L"■ ■ □ □ □";
      else if(lengthScore == 8) lengthProgressBar = L"■ ■ ■ □ □";
      else if(lengthScore >= 9 && lengthScore < 11) lengthProgressBar = L"■ ■ ■ ■ □";
      else if(lengthScore >= 11) lengthProgressBar = L"■ ■ ■ ■ ■";
      
      if(growthScore == 3) growthProgressBar = L"□ □ □ □ □";
      else if(growthScore == 4 || growthScore == 5) growthProgressBar = L"■ □ □ □ □";
      else if(growthScore == 6) growthProgressBar = L"■ ■ □ □ □";
      else if(growthScore == 7) growthProgressBar = L"■ ■ ■ □ □";
      else if(growthScore == 8) growthProgressBar = L"■ ■ ■ ■ □";
      else if(growthScore >= 9) growthProgressBar = L"■ ■ ■ ■ ■";
      
      if(poisonScore == 0) poisonProgressBar = L"□ □ □ □ □"; 
      else if(poisonScore ==1) poisonProgressBar = L"■ □ □ □ □";
      else if(poisonScore ==2) poisonProgressBar = L"■ ■ ■ □ □";
      else if(poisonScore ==3) poisonProgressBar = L"■ ■ ■ ■ □";
      else if(poisonScore >=4) poisonProgressBar = L"■ ■ ■ ■ ■";
      
      if(gateScore == 0) gateProgressBar = L"□ □ □ □ □"; 
      else if(gateScore ==1) gateProgressBar = L"■ □ □ □ □";
      else if(gateScore ==2) gateProgressBar = L"■ ■ ■ □ □";
      else if(gateScore ==3) gateProgressBar = L"■ ■ ■ ■ □";
      else if(gateScore >=4) gateProgressBar = L"■ ■ ■ ■ ■";
      break;
      
    //Stage 5 
    case 4:
      if(lengthScore == 3) lengthProgressBar = L"□ □ □ □ □";
      else if(lengthScore >= 4 && lengthScore < 6) lengthProgressBar = L"■ □ □ □ □";
      else if(lengthScore >= 6 && lengthScore < 8) lengthProgressBar = L"■ ■ □ □ □";
      else if(lengthScore >= 8 && lengthScore < 10) lengthProgressBar = L"■ ■ ■ □ □";
      else if(lengthScore >= 10 && lengthScore < 12) lengthProgressBar = L"■ ■ ■ ■ □";
      else if(lengthScore >= 12) lengthProgressBar = L"■ ■ ■ ■ ■";
      
      if(growthScore == 3) growthProgressBar = L"□ □ □ □ □";
      else if(growthScore == 4 || growthScore == 5) growthProgressBar = L"■ □ □ □ □";
      else if(growthScore >= 6 && growthScore < 8) growthProgressBar = L"■ ■ □ □ □";
      else if(growthScore == 8) growthProgressBar = L"■ ■ ■ □ □";
      else if(growthScore >= 9 && growthScore < 11) growthProgressBar = L"■ ■ ■ ■ □";
      else if(growthScore >= 11) growthProgressBar = L"■ ■ ■ ■ ■";
      
      if(poisonScore == 0) poisonProgressBar = L"□ □ □ □ □"; 
      else if(poisonScore ==1) poisonProgressBar = L"■ □ □ □ □";
      else if(poisonScore ==2) poisonProgressBar = L"■ ■ □ □ □";
      else if(poisonScore ==3) poisonProgressBar = L"■ ■ ■ □ □";
      else if(poisonScore ==4) poisonProgressBar = L"■ ■ ■ ■ □";
      else if(poisonScore >=5) poisonProgressBar = L"■ ■ ■ ■ ■";
          
      if(gateScore == 0) gateProgressBar = L"□ □ □ □ □"; 
      else if(gateScore ==1) gateProgressBar = L"■ □ □ □ □";
      else if(gateScore ==2) gateProgressBar = L"■ ■ □ □ □";
      else if(gateScore ==3) gateProgressBar = L"■ ■ ■ □ □";
      else if(gateScore ==4) gateProgressBar = L"■ ■ ■ ■ □";
      else if(gateScore >=5) gateProgressBar = L"■ ■ ■ ■ ■";
      break;
  }
  
  mvprintw(12, CHAR_X + 7, "%ls", lengthProgressBar.c_str()); 
  mvprintw(14, CHAR_X + 7, "%ls", growthProgressBar.c_str()); 
  mvprintw(16, CHAR_X + 7, "%ls", poisonProgressBar.c_str()); 
  mvprintw(18, CHAR_X + 7, "%ls", gateProgressBar.c_str()); 
  
  mvaddstr(12, CHAR_X + 17, "( )"); 
  mvaddstr(14, CHAR_X + 17, "( )"); 
  mvaddstr(16, CHAR_X + 17, "( )"); 
  mvaddstr(18, CHAR_X + 17, "( )");
  
  
  if(lengthScore >= currentMission[0]){
  	lengthCleared = true;
  	mvaddstr(12, CHAR_X + 18, "V"); 
  } 
  else{
  	lengthCleared = false;
  	mvaddstr(12, CHAR_X + 18, " "); 
  }
  if(growthScore >= currentMission[1]){
  	growthCleared = true;
  	mvaddstr(14, CHAR_X + 18, "V"); 
  }
  if(poisonScore >= currentMission[2]){
  	poisonCleared = true;
  	mvaddstr(16, CHAR_X + 18, "V"); 
  }
  if(gateScore >= currentMission[3]){
  	gateCleared = true;
  	mvaddstr(18, CHAR_X + 18, "V"); 
  }
  
}

int ScoreBoard::getCurrentStage(){
  return stageManager.getCurrentStage();
}

void ScoreBoard::increase(const int item){
  switch (item){
    case 5: //Growth Item
      stageManager.increaseGrowthScore();
      stageManager.increaseLengthScore();
      break;
    case 6: //Poison Item
      stageManager.increasePoisonScore();
      stageManager.decreaseLengthScore();
      break;
    case 7: //Gate 
      stageManager.increaseGateScore();
      break;
  }
}

bool ScoreBoard::isCleared(bool &length, bool &growth, bool &poison, bool &gate){
  if (length && growth && poison && gate){
    length = false;
    growth = false;
    poison = false;
    gate = false;
    resetScore();
    stageManager.nextStage();
    
    return true;
  }
  else{
    return false;
  }
}
void ScoreBoard::resetScore(){
  stageManager.resetScore();
}

