// Helper functions for music

#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';

    while (denominator != 8)
    {
        numerator *= 2;
        denominator *= 2;
    }
    return numerator;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int octave;
    int adjust = 0;

    if (strlen(note) == 3) // indicates an accidental is present
    {
        char accidental = note[1];
        octave = atoi(&note[2]);

        if (accidental == '#')
        {
            adjust += 1; // increment by 1 for sharps

        }

        else if (accidental == 'b')
        {
            adjust -= 1; // increment by 1 for flats
        }
    }
    else
    {
        octave = atoi(&note[1]); // proceed with octave as the second character
    }

    char n = note[0];

    // adjust semitones for distance from 'A'
    if (n == 'A')
    {
        adjust += 0;
    }
    else if (n == 'B')
    {
        adjust += 2;
    }
    else if (n == 'C')
    {
        adjust -= 9;
    }
    else if (n == 'D')
    {
        adjust -= 7;
    }
    else if (n == 'E')
    {
        adjust -= 5;
    }
    else if (n == 'F')
    {
        adjust -= 4;
    }
    else if (n == 'G')
    {
        adjust -= 2;
    }

    adjust += (octave - 4) * 12;

    float adjustor = adjust / 12.0;
    float Hz = round(pow(2, adjustor) * 440);
    return Hz;
}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
