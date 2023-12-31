/* インクルードガード */
#pragma once

#include "M5All-In-One-Gadget.h"
#include "MdDateTime.h"
#include "MdLcd.h"
#include "MdMeasureDistance.h"
#include "MdMusicPlayer.h"
#include "MdWBGTMonitor.h"
typedef struct
{
    String Date;
    String Time;
    int count;
    int x;
    int y;
} HALData;
class AppControl // classの定義
{
private: // privateはクラス内からしかアクセスできない
    bool m_flag_btnA_is_pressed = false;
    bool m_flag_btnB_is_pressed = false;
    bool m_flag_btnC_is_pressed = false;

    /* State Machine */
    State m_state = TITLE;
    Action m_action = ENTRY;

    /* HighAndLow */
    HighAndLowState hl_state = QUESTION;

    /* GUI State */
    FocusState m_focus_state = MENU_WBGT;

    HALData Record[10];

public: // publicはどこからでもアクセス可能
    State getState();
    void setState(State state);
    Action getAction();
    void setAction(Action action);
    HighAndLowState getHighAndLowState();
    void setHighAndLowState(HighAndLowState state);
    FocusState getFocusState();
    void setFocusState(FocusState fs);

    void setBtnAFlg(bool flg);
    void setBtnBFlg(bool flg);
    void setBtnCFlg(bool flg);
    void setBtnAllFlgFalse();
    void setStateMachine(State state, Action action);
    void displayTitleInit();
    void displayMenuInit();
    void focusChangeImg(FocusState current_state, FocusState next_state);
    void displayWBGTInit();
    void displayTempHumiIndex();
    void displayMusicInit();
    void displayMusicStop();
    void displayMusicTitle();
    void displayNextMusic();
    void displayMusicPlay();
    void displayMeasureInit();
    void displayMeasureDistance();
    void displayDateInit();
    void displayDateUpdate();
    void controlApplication();
    void displayHIGHANDLOWTitleInit();
    void displayHIGHANDLOWPlayQuestion(int* trumpL);
    void displayHIGHANDLOWPlayRandom(int *trump);
    void displayHIGHANDLOWPlayResult(HighAndLowState state, int *trumpR);
    void setHIGHANDLOWRecordData(HALData *Record, int win);
    void displayHIGHANDLOWRecord();
};