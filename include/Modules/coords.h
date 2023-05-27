#ifndef COORDS_H
#define COORDS_H

// constants
#define MAXCOORDS 64


// coord struct
typedef struct {
        unsigned row, col ; // rows & cols
} tcoord ;

// coords struct
typedef struct {
	unsigned ncoords ; // 'head' is the position 0, 'tail' is the position ncoords-1 
	tcoord coord[MAXCOORDS] ;
} tcoords ;



// functions
void in_coord(tcoord *c); // initialize a random coord
void in_coords(tcoords *cs); // initialize worm in the middle of the board
void insert_pos(tcoords *cs); // return 0 if it's ok, <> 0 error pos out of range 

#endif