/*
 * Copyright (c) 2004 Matthijs Hollemans
 * Copyright (c) 2008-2014 Haiku, Inc. All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 */


#include "SynthBridge.h"


//	#pragma mark - SynthBridge


SynthBridge::SynthBridge()
	:
	BMidiLocalConsumer("Internal Synthesizer")
{
}


bool
SynthBridge::Init(synth_mode mode)
{
	if (be_synth->LoadSynthData(mode) == B_OK) {
		fMidiSynth.EnableInput(true, true);
		return true;
	}

	return false;
}


BMidiSynth*
SynthBridge::MidiSynth()
{
	return &fMidiSynth;
}


void
SynthBridge::NoteOff(uchar channel, uchar note, uchar velocity, bigtime_t time)
{
	fMidiSynth.NoteOff(channel + 1, note, velocity, time / 1000);
}


void
SynthBridge::NoteOn(uchar channel, uchar note, uchar velocity, bigtime_t time)
{
	fMidiSynth.NoteOn(channel + 1, note, velocity, time / 1000);
}


void
SynthBridge::KeyPressure(uchar channel, uchar note, uchar pressure,
	bigtime_t time)
{
	fMidiSynth.KeyPressure(channel + 1, note, pressure, time / 1000);
}


void
SynthBridge::ControlChange(uchar channel, uchar controlNumber,
	uchar controlValue, bigtime_t time)
{
	fMidiSynth.ControlChange(channel + 1, controlNumber, controlValue,
		time / 1000);
}


void
SynthBridge::ProgramChange(uchar channel, uchar programNumber, bigtime_t time)
{
	fMidiSynth.ProgramChange(channel + 1, programNumber, time / 1000);
}


void
SynthBridge::ChannelPressure(uchar channel, uchar pressure, bigtime_t time)
{
	fMidiSynth.ChannelPressure(channel + 1, pressure, time / 1000);
}


void
SynthBridge::PitchBend(uchar channel, uchar lsb, uchar msb, bigtime_t time)
{
	fMidiSynth.PitchBend(channel + 1, lsb, msb, time / 1000);
}


void
SynthBridge::AllNotesOff(bool justChannel, bigtime_t time)
{
	fMidiSynth.AllNotesOff(justChannel, time / 1000);
}
