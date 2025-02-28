#include "error-assert.h"
#include "heap-sort.h"
#include "merge-sort.h"
#include "metrics.h"
#include "parser.h"
#include "quick-sort.h"
#include "record.h"
#include "usage.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  // input params
  Params params = parse_arguments(argc, argv);

  // input file
  FILE *input = fopen(params.input_file, "r");
  error_assert((input != NULL), "Failed to open the input file.");

  // output file
  FILE *output = fopen(params.output_file, "w");
  error_assert((output != NULL), "Failed to open the output file.");

  // write the output header line
  fprintf(output, "%s v=%d", params.alg_name, params.version);
  if (params.version == 2) {
    fprintf(output, " k=%d", params.k);
  } else if (params.version == 3) {
    fprintf(output, " m=%d", params.m);
  }
  fprintf(output, "\n");

  // for each test case
  int test_size;
  while (fscanf(input, "%d", &test_size) == 1) {
    // create the list of records
    Record *records = generate_records(test_size, params.seed);

    // reset algorithm metrics
    reset_metrics();

    // init rusage
    struct rusage usage_start = set_usage();
    double start_time = get_proc_time(&usage_start);

    if (strcmp(params.alg_name, QUICKSORT) == 0) {
      switch (params.version) {
      case 1:
        quick_sort_rec(records, test_size);
        break;
      case 2:
        quick_sort_k_median(records, test_size, params.k);
        break;
      case 3:
        quick_sort_selection(records, test_size, params.m);
        break;
      case 4:
        quick_sort_iterative(records, test_size);
        break;
      case 5:
        quick_sort_smart_stack(records, test_size);
        break;
      default:
        break;
      }
    } else if (strcmp(params.alg_name, HEAPSORT) == 0) {
      heap_sort(records, test_size);
    } else if (strcmp(params.alg_name, MERGESORT) == 0) {
      merge_sort(records, test_size);
    }

    // finish usage
    struct rusage end_usage = set_usage();
    double end_time = get_proc_time(&end_usage);

    double usage_time = end_time - start_time;

    // print the result in the output file
    fprintf(output, "%d %lld %lld %.5f\n", test_size, compared, copied,
            usage_time);

    // free allocated memory
    clean_records(records);
  }

  fclose(input);
  fclose(output);

  return 0;
}
