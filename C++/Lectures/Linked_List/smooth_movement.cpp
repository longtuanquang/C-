#pragma once
float Approach(float fGoal, float fCurrent, float dt){
    float fDiff = fGoal - fCurrent;
    if(fDiff > dt){
        return fCurrent + dt;
    }
    if(fDiff < -dt){
        return fCurrent - dt;
    }
    return fGoal;
}