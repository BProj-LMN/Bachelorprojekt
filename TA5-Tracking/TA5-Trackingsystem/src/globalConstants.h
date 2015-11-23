/*
 * globalConstants.h
 *
 * function: define global enums and functions, error handling, ...
 *
 * author: Jannik Beyerstedt
 */

#ifndef SRC_GLOBALCONSTANTS_H_
#define SRC_GLOBALCONSTANTS_H_

enum {
  ERROR = -1, OK = 0
};

enum {
  FALSE = 0, TRUE = 1
};

/*
 * error scheme
 *
 * fprintf(stderr, "ERROR: in {functionName} - {custom message, error codes, etc.} \n");
 */

#endif /* SRC_GLOBALCONSTANTS_H_ */
