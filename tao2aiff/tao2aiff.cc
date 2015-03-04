/* Tao - A software package for sound synthesis with physical models
 * Copyright (C) 1993-1999 Mark Pearson
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>
#include <fstream>
#include <cmath>
#include "audiofile.h"
#include "tao2aiff.h"


int main(int argc, char **argv)
    {
    char AIFFfilename[256];
    char infilename[256];
    char fileid[20];
    AFfilesetup setup;
    AFfilehandle outfile;
    std::ifstream infile;
    float maxSample=0.0;
    int audioRate;
    int numChannels;
    float scaleBy;
    int totalNumSamples;
    int numSamplesRead;
    float floatSamples[1000];
    short shortSamples[1000];
    int sampleIndex;
    std::streampos sampleData;
    
    if (argc < 3)
	{
	std::cerr << "usage: taosf <infile> <outfile>\n";
	exit(1);
	}
	
    argv++; strcpy(infilename, *argv);
    argv++; strcpy(AIFFfilename, *argv);
    
// Create a new AFfilesetup structure and set file format, sample format,
// sample rate etc.

    std::cout << "Opening input file: " << infilename << std::endl;

    infile.open(infilename);

    if (!infile)
	{
	std::cerr << "Error opening input file: " << infilename << ", aborting\n";
	exit(1);
	}

// Open the input file and check that it is a Tao output file. If it is, read
// sample rate and number of channels and create the `filesetup' structure which
// will be used to write the AIFF file header.
   
    infile.read((char *)&fileid[0], 15);
    fileid[15]='\0';

    if (strcmp(fileid, "TAO OUTPUT FILE")!=0)
        {
	std::cerr << "Error: " << infilename << " is not a Tao output file, aborting\n";
	exit(1);
	}

    infile.read((char *)&audioRate, sizeof(int));
    infile.read((char *)&numChannels, sizeof(int));
        
    std::cout << "Audio rate: " << audioRate << std::endl;
    std::cout << "Number of channels: " << numChannels << std::endl;
    std::cout << "Checking for maximum sample value...\n";

    sampleData=infile.tellg();

    while(1)
	{
        infile.read((char *)&floatSamples[0], 1000*sizeof(float));
	numSamplesRead=(int)infile.gcount()/sizeof(float);

	for (sampleIndex=0;sampleIndex<numSamplesRead;sampleIndex++)
	    {	
	    if (fabs(floatSamples[sampleIndex])>maxSample)
	        maxSample=fabs(floatSamples[sampleIndex]);
	    }
	if (infile.eof()) break;
	}

    std::cout << "Maximum sample value: " << maxSample << std::endl;

    setup=afNewFileSetup();
    afInitFileFormat(setup, AF_FILE_AIFF);
    afInitRate(setup, AF_DEFAULT_TRACK, (double)audioRate);
    afInitSampleFormat(setup, AF_DEFAULT_TRACK, AF_SAMPFMT_TWOSCOMP, 16);
    afInitChannels(setup, AF_DEFAULT_TRACK, numChannels);

// Open the output file.

    std::cout << "Opening output file: " << AIFFfilename << std::endl;

    outfile=afOpenFile(AIFFfilename, "w", setup);
    if (outfile==AF_NULL_FILEHANDLE)
	{
	std::cerr << "Error opening output file: " << AIFFfilename << ", aborting\n";
	exit(1);
	}

    infile.clear();
    infile.seekg(sampleData);
     
    std::cout << "Writing normalised samples" << std::endl;

    scaleBy=32700.0f/maxSample;
        
    while(1)
        {
        infile.read((char *)&floatSamples[0], 1000*sizeof(float));
	numSamplesRead=infile.gcount()/sizeof(float);

	for (sampleIndex=0;sampleIndex<numSamplesRead;sampleIndex++)
	    {	
	    shortSamples[sampleIndex]=
		(short)(floatSamples[sampleIndex]*scaleBy);
	    }

        afWriteFrames(outfile, AF_DEFAULT_TRACK, (void *)&shortSamples[0], 
			     numSamplesRead/numChannels);
	
	totalNumSamples+=1000;
	if (totalNumSamples%10000==0)
	    {
	    std::cout << "." << std::flush;
	    }
	if (infile.eof()) break;
	}	

    std::cout << "Successfully wrote AIFF file: " << AIFFfilename << std::endl;
    infile.close();
    afCloseFile(outfile);

// Free AFfileestup structure as we don't need it any more

    afFreeFileSetup(setup);
    }

//$Id: tao2aiff.cc,v 1.3 2000/01/05 00:24:05 tao Exp $
//$Log: tao2aiff.cc,v $
//Revision 1.3  2000/01/05 00:24:05  tao
//Added GPL info to head of file.
//
//Revision 1.2  1999/11/14 02:15:30  tao
//*** empty log message ***
//
//Revision 1.1.1.1  1999/08/30 21:17:33  tao
//Imported Tao sources
//
//Revision 0.9  1998/09/25 02:10:55  mdp
//Added RCS Id and Log to head of file.
//
