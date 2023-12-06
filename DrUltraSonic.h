/* インクルードガード */
#pragma once

class DrUltraSonic // classの定義
{
private: // privateはクラス内からしかアクセスできない
public: // publicはどこからでもアクセス可能
void DrUltraSonic(int echo_pin,int trig_pin);
double measureReturnTime();
};
