
#pragma once
#include "readFile.h"
class Edge
{
  public:
    Airport source; /**< The source of the edge **/
    Airport dest; /**< The destination of the edge **/

    Edge(Airport u, Airport v) {
        source = u;
        dest = v;
    }
  
};
