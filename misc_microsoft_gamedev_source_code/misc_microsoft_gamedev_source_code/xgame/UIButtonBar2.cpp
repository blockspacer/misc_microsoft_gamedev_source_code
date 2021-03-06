//============================================================================
// UIButtonBar2.cpp
// Ensemble Studios (c) 2007
//============================================================================

#include "common.h"
#include "uibuttonbar2.h"

//-- render
/*
#include "render.h"
#include "renderDraw.h"
#include "renderThread.h"

#include "camera.h"
#include "user.h"
#include "usermanager.h"
#include "player.h"
#include "uigame.h"
#include "visualmanager.h"
#include "database.h"
#include "world.h"
#include "hpbar.h"
#include "FontSystem2.h"
#include "timermanager.h"
#include "configsgame.h"
#include "statsManager.h"
#include "graphmanager.h"
#include "protosquad.h"
*/

//==============================================================================
// BUIButtonBar2::setButtonStates
//==============================================================================
void BUIButtonBar2::setButtonTexts(const BUString& text1,
                                  const BUString& text2,
                                  const BUString& text3,
                                  const BUString& text4,
                                  const BUString& text5,
                                  const BUString& text6,
                                  const BUString& text7 )
{
   if (!mpMovie)
      return;

   GFxValue values[7];

   values[0].SetStringW(text1.getPtr());
   values[1].SetStringW(text2.getPtr());
   values[2].SetStringW(text3.getPtr());
   values[3].SetStringW(text4.getPtr());
   values[4].SetStringW(text5.getPtr());
   values[5].SetStringW(text6.getPtr());
   values[6].SetStringW(text7.getPtr());

   invokeActionScript("setButtonTexts", values, 7);
}

//==============================================================================
// BUIPartyRoom::setButtonStates
//==============================================================================
void BUIButtonBar2::setButtonStates(uint state1, uint state2, uint state3, uint state4, uint state5, uint state6, uint state7)
{
   if (!mpMovie)
      return;

   GFxValue values[7];
   values[0].SetNumber(state1);
   values[1].SetNumber(state2);
   values[2].SetNumber(state3);
   values[3].SetNumber(state4);
   values[4].SetNumber(state5);
   values[5].SetNumber(state6);
   values[6].SetNumber(state7);

   invokeActionScript("setButtonStates", values, 7);
}

//==============================================================================
// BUIButtonBar2::invokeActionScript
//==============================================================================
void BUIButtonBar2::invokeActionScript(const char* method, const GFxValue* pArgs, int numArgs)
{
   BSimString function;
   getASName(function, method);
   mpMovie->invokeActionScript(function.getPtr(), pArgs, numArgs);
}


//==============================================================================
// BUIButtonBar2::getASName
//==============================================================================
void BUIButtonBar2::getASName(BSimString& fullName, const char* methodName)
{
   if (mMovieClipName.isEmpty())
      fullName.set(methodName);
   else
      fullName.format("%s.%s", mMovieClipName.getPtr(), methodName);
}
