/*****************************************************************************
  mapBed.h

  (c) 2009 - Aaron Quinlan
  Hall Laboratory
  Department of Biochemistry and Molecular Genetics
  University of Virginia
  aaronquinlan@gmail.com

  Licenced under the GNU General Public License 2.0 license.
******************************************************************************/
#ifndef MAPBED_H
#define MAPBED_H

#include "bedFile.h"
#include "chromsweep.h"
#include "api/BamReader.h"
#include "api/BamWriter.h"
#include "api/BamAux.h"
#include "BamAncillary.h"
using namespace BamTools;


#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;



class BedMap {

public:

    // constructor
    BedMap(string bedAFile, string bedBFile, int column, string operation,
                   float overlapFraction, bool sameStrand, 
                   bool diffStrand, bool reciprocal, 
                   bool printHeader);

    // destructor
    ~BedMap(void);

private:

    //------------------------------------------------
    // private attributes
    //------------------------------------------------
    string _bedAFile;
    string _bedBFile;
    int _column;
    string _operation;
    bool  _sameStrand;
    bool  _diffStrand;
    bool  _reciprocal;
    float _overlapFraction;

    bool  _printHeader;
    
    // instance of a bed file class.
    BedFile *_bedA, *_bedB;

    //------------------------------------------------
    // private methods
    //------------------------------------------------
    void Map();
    
    void ApplyHits(const BED &a, const vector<BED> &hits);

};

#endif /* MAPBED_H */
