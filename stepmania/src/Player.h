#pragma once
/*
-----------------------------------------------------------------------------
 Class: Player

 Desc: Object that accepts pad input, knocks down ColorNotes that were stepped on, 
		and keeps score for the player.

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/

#include "PrefsManager.h"	// for GameplayStatistics
#include "Notes.h"
#include "Sprite.h"
#include "BitmapText.h"

#include "ColorNote.h"
#include "GrayArrow.h"
#include "GhostArrow.h"
#include "GhostArrowBright.h"
#include "HoldGhostArrow.h"
#include "ActorFrame.h"
#include "RandomSample.h"
#include "ScoreDisplay.h"
#include "LifeMeterBar.h"
#include "Judgement.h"
#include "HoldJudgement.h"
#include "Combo.h"
#include "NoteField.h"
#include "GrayArrowRow.h"
#include "GhostArrowRow.h"
#include "NoteDataWithScoring.h"


class Player : public NoteDataWithScoring, public ActorFrame
{
public:
	Player();

	virtual void Update( float fDeltaTime );
	virtual void DrawPrimitives();

	void Load( PlayerNumber player_no, NoteData* pNoteData, LifeMeter* pLM, ScoreDisplay* pScore );
	void CrossedRow( int iNoteRow );
	void Step( int col );


	void	SetOverrideAdd( float fAdd )	{ m_NoteField.m_fOverrideAdd = fAdd; };
	float	GetOverrideAdd()				{ return m_NoteField.m_fOverrideAdd; };

protected:
	int UpdateTapNotesMissedOlderThan( float fMissIfOlderThanThisBeat );
	void OnRowDestroyed( int col, int iStepIndex );
	void HandleNoteScore( TapNoteScore score );
	void HandleNoteScore( HoldNoteScore score );

	static float GetMaxBeatDifference();

	PlayerNumber	m_PlayerNumber;

	float			m_fHoldNoteLife[MAX_TAP_NOTE_ROWS];	// 1.0 means this HoldNote has full life.
														// 0.0 means this HoldNote is dead
														// When this value hits 0.0 for the first time, 
														// m_HoldScore becomes HSS_NG.
														// If the life is > 0.0 when the HoldNote ends, then
														// m_HoldScore becomes HSS_OK.
	int				m_iNumTapNotes;	// num of TapNotes for the current notes needed by scoring
	int				m_iTapNotesHit;	// number of notes judged so far, needed by scoring
	int				m_iMeter;		// meter of current steps, needed by scoring

	GrayArrowRow		m_GrayArrowRow;
	NoteField			m_NoteField;
	GhostArrowRow		m_GhostArrowRow;

	HoldJudgement			m_HoldJudgement[MAX_NOTE_TRACKS];

	ActorFrame				m_frameJudgement;
	Judgement				m_Judgement;
	
	ActorFrame				m_frameCombo;
	Combo					m_Combo;

	LifeMeter*				m_pLifeMeter;
	ScoreDisplay*			m_pScore;
	
};
