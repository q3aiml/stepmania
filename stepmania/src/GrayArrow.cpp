#include "stdafx.h"
/*
-----------------------------------------------------------------------------
 Class: GrayArrow

 Desc: A gray arrow that "receives" ColorNotes.

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Ben Nordstrom
	Chris Danford
-----------------------------------------------------------------------------
*/

#include "GrayArrow.h"
#include "PrefsManager.h"
#include "GameState.h"


const float GRAY_ARROW_POP_UP_TIME	= 0.15f;


GrayArrow::GrayArrow()
{
	StopAnimating();
}

void GrayArrow::Update( float fDeltaTime )
{
	Sprite::Update( fDeltaTime );

	int iNewState = (int)( fmod(GAMESTATE->m_fSongBeat,1) * Sprite::GetNumStates() );
	if( iNewState < 0 )
		iNewState += Sprite::GetNumStates();
	SetState( iNewState );
}

void GrayArrow::Step()
{
	SetZoom( 0.75f );
	BeginTweening( GRAY_ARROW_POP_UP_TIME );
	SetTweenZoom( 1.0f );
}
