/*
 smith_waterman.h
 author: Isaac Turner <turner.isaac@gmail.com>
 url: https://github.com/noporpoise/seq-align
 May 2013
 */

#ifndef SMITH_WATERMAN_HEADER_SEEN
#define SMITH_WATERMAN_HEADER_SEEN

#include "alignment.h"

typedef struct sw_aligner_t sw_aligner_t;

sw_aligner_t *smith_waterman_new();
void smith_waterman_free(sw_aligner_t *sw_aligner);

aligner_t* smith_waterman_get_aligner(sw_aligner_t *sw);

/*
 Do not alter seq_a, seq_b or scoring whilst calling this method
 or between calls to smith_waterman_get_hit
*/
void smith_waterman_align(const char *seq_a, const char *seq_b,
                          const scoring_t *scoring, sw_aligner_t *sw);

void smith_waterman_align2(const char *seq_a, const char *seq_b,
                           size_t len_a, size_t len_b,
                           const scoring_t *scoring, sw_aligner_t *sw);

// An alignment to read from, and a pointer to memory to store the result
// returns 1 if an alignment was read, 0 otherwise
int smith_waterman_fetch(sw_aligner_t *sw, alignment_t *result);

#endif
