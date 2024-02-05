#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

#include "log.h"

/*
 *
 * returns true if the wcs argument is
 * fully blank
 *
 */
bool iswsblank(wchar_t *wcs) {

  bool fully_blank = true;

  if (wcs[0] == L'\0') {
    return fully_blank;
  }

  for (int i = 0; i <= wcslen(wcs) - 1; i++) {
    if (!iswblank(wcs[i])) {
      fully_blank = false;
    }
  }
  return fully_blank;
}

/*
 *
 * returns:
 * 	- a pointer to the recently assigned buff
 *
 */
wchar_t *prompt_wcs(wchar_t *buff, int size) {
  errno = 0;
  wchar_t *tmpbuff = fgetws(buff, size, stdin);
  if (tmpbuff == NULL) {
    log_error(L"Error: Couldn't read from stdin\n");
    if (errno == EILSEQ) {
      log_warning(L"Invalid character encounterd.\n");
    } else if (feof(stdin)) {
      // nothing, just reached the fucking WEOF
    } else {
      log_warning(L"Some error ocurrend while reading input\n");
    }
  }
  // this removes \n for the tmp buffer
  // 	- this happens cause cause fgetws()
  // 	func reads from current stream position
  // 	TO AND INCLUDING the FIRST NEW LINE CHAR,
  //
  //	As a result wcslen(wchar_t[] - 1)
  //	is a newline character (LN, CR,
  //	LNCR, etc..).
  //
  //	- wchar_t end if a NUL WIDE CHAR(\0)
  //	so above \n can't be last)
  //
  //
  tmpbuff[wcslen(tmpbuff) - 1] = L'\0';
  return tmpbuff; // at this point fgetws already set
                  // tmpbuff to either NULL or a valid pointer
}

/*
 * Description:
 * 	- Prompts from an integer value
 * 	from stdin and assigns it to the pointer
 * 	passed as arg
 * returns:
 * 	- true if success assiging &opt
 * 	- false if mf hasn't entered valid opt OR
 * 	if reached EOF (aka mf presses enter key)
 *
 */
bool prompt_option(int *opt) {

  wchar_t buff[10];
  errno = 0;

  if (fgetws(buff, 10, stdin) == NULL) {
    wprintf(L"Error: Couldn't read from stdin\n");
    if (errno == EILSEQ) {
      log_warning(L"Invalid character encounterd.\n");
    } else if (feof(stdin)) {
      // nothing, just reached the fucking WEOF
    } else {
      log_warning(L"Some error ocurrend while reading input\n");
    }
  } else {
    // could read input, now to do some fucking convertion
    errno = 0;
    bool success = false;
    int scan_rs = swscanf(buff, L"%d", opt);

    if (errno == EINVAL) {
      log_error(L"Invalid argument for swscanf func\n");
    }

    if (scan_rs == 1) {
      success = true;
    } else if (scan_rs == EOF) {
      // mf pressed enter so shuld re-prompt on caller func
    } else {
      log_warning(L"Invalid option, try entering a number...\n");
    }
    return success;
  }
  return false;
}

/*
 * Propmts user for input until enters a valid value to
 * persist/store in .csv file. It then assigns that into buff argument
 * It uses 'label' param to prompt for input and log msgs
 *
 */
void prompt_storable_input(wchar_t *buff, int size, wchar_t *label) {
  bool valid = false;
  while (true) {
    do {
      wprintf(L"%ls: ", label);
    } while (prompt_wcs(buff, size) == NULL);

    if (wcschr(buff, L',') != NULL) {
      log_warning(L"%ls can't contain commas(,), use dots(.) instead\n", label);
      continue;
    } else if (iswsblank(buff)) {
      log_warning(L"%ls can't be blank, try again...\n", label);
      continue;
    } else {
      valid = true;
      break;
    }
  }
}
