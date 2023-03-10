/*==============================================================*/
/* 화 일  명: IGIetc.h                                          */
/* 제  목:                                                      */
/*--------------------------------------------------------------*/
/* 라이브러리:                                                  */
/* 작 성  자: 강영익                                            */
/* 헤더화일: IGIetc.h                                           */
/* 작 성  일: 05.1.01( 최종수정일 :  .  .)                      */
/*--------------------------------------------------------------*/
/* 기  능:                                                      */
/*                                                              */
/*--------------------------------------------------------------*/
/*
 * $Log: IGIetc.h,v $
 * Revision 1.5  2005/01/25 11:50:14  root
 * GetFileSize 함수 추가
 *
 * Revision 1.4  2005/01/25 10:12:23  root
 * lock 함수 추가
 *
 * Revision 1.3  2005/01/20 05:15:55  root
 * isExistFile 함수 추가
 *
 * Revision 1.2  2005/01/19 07:00:31  root
 * ^M 삭제
 *
 * Revision 1.1  2005/01/19 02:29:46  root
 * Initial revision
 *
 *                                                              */
/*--------------------------------------------------------------*/
#ifndef _IGIETC_H_


#define _IGIETC_H_


/*---------------------------------------
 * INI 파일의 변수 및 값에 대한 최대 길이
 * 정의 Makefile로 이동함
 * #define MAX_INI_STRING_LENGTH  256
 *---------------------------------------*/

#ifndef MAX_STRING_LENGTH
#define MAX_STRING_LENGTH 1024
#endif

/*=============================================================
 * 함수명 : void IGIeraseLBlank(char *s)
 * 기능   : 문자열 s의 왼쪽 공백을 지워주는 부분.
 * 반환   : 없음
 * 사용예 : char *s = "   abcd efg ";
 *
 *          IGIeraseLBlank(s);
 *          s  ->   "abcd efg "
--------------------------------------------------------------*/
void IGIeraseLBlank(char *s);


/*=============================================================
 * 함수명 : void IGIeraseRBlank(char *s)
 * 기능   : 문자열 s의 오른쪽 공백을 지워주는 부분
 * 반환   : 없음
 * 사용예 : char *s = "   abcd efg ";
 *          IGIeraseRBlank(s);
 *          s  ->    "    abcd efg"
-------------------------------------------------------------*/
void IGIeraseRBlank(char *s);


/*=============================================================
 * 함수명 : void IGIeraseBlank(char *s)
 * 기능   : 문자열 s의 좌우 공백을 지워주는 부분
 * 반환   : 없음
 * 사용예 : char *s = "   abcd efg ";
 *          IGIeraseBlank(s);
 *          s  ->    "abcd efg"
 *------------------------------------------------------------*/
void IGIeraseBlank(char *s);


/*=============================================================
 * 함수명: IGIgetEnvIni(char *ininame, char *group, char *var)
 *
 * 인  수: ininame : 조회할 INI파일 명
 *         group   : 조회할 GROUP 이름
 *         var     : 조회할 변수명
 *
 * 기능  : ininame의 파일에서 group에 정의된 변수의 등록 
 *         정보를 얻는다.
 *         ini파일의 내용은 # 은 주석으로 처리되며,
 *         그룹은 [GROUP_NAME] 의 형식으로 그룹 이름이 
 *         '[]' 안에 기술된다.
 *         각 그룹의 구분은 새로운 그룹이름이 나오기 전까지 
 *         등록된 값을 그룹내의 정의된 변수/값으로 간주한다.
 *         변수와 값은  var=value 형식으로 기술된다.
 *         value값은 좌우측에는 SPACE가 있으면 무시가 되며, 
 *         문자열 사이에 SPACE가 있을 경우는 SPACE자체를 
 *         value로 인정한다.
 *
 * 반환  : 조회 성공했을 때, 조회한 var의 값을 반환하며,
 *         오류가 발생했을 때, NULL을 반환한다.
 *
 * 참고사항: 내부에서 static 변수를 사용한다.
 *           value의 최대 길이는 200으로 제한된다.
 *
 * 사용예: robot.ini 파일의  "AGENT" 그룹의 "POOL"에 정의된 
 *         값을 얻고자 할경우
 *         s = IGIgetEnvIni("robot.ini", "AGENT", "POOL");
 *         if (s == NULL) printf("error");
 *
 *
 *----------------------------------------------------------*/
char *IGIgetEnvIni(char *ininame, char *group, char *var);


/*-----------------------------------------------------------
 * 함수명 : get_curdate
 * 기능   : 현재의 날짜/시간 을 얻는다.
 * 반환   : 시간값
 *
 *---------------------------------------------------------*/
struct tm *get_curdate();



/*=========================================================
 * 함수명 : IGIisMatch(char s[], char key[])
 * 인수   : s 는  검색하게될 대상이 되는 문자열
 *          key는 검색의 키로 사용될 문자열로 
 *          '*', '?'등의 문자로 표현될수있다.
 * 기능   : key로 사용된 문자열에 s가 포함되는지를 찾는 
 *          함수
 * 반환   : 문자열(s)가 key에 포함된다면 1을, 아니면 0을 
 *          반환
 *
 * 사용예 :  IGIisMatch("abcdefg", "abcdefg")  =>  1
 *           IGIisMatch("abcdefg", "abcdeff")  =>  0
 *           IGIisMatch("abcdefg", "abc*")     =>  1
 *           IGIisMatch("abcdefg", "abc??fg")  =>  1
 *           IGIisMatch("abcdefg", "a*c??fg")  =>  1
 *           IGIisMatch("abcdefg", "*c??fg")   =>  1
 *
 * 주의사항: 아직 완전한 검증을 받지 못함.. 테스트는 
 *           했는데.... 오랜 테스트
 * 시간없이 경우의 수만을 만들어서 만든 테스트라서 
 * 완전한 검증이되지 못했다.
 * 라이브러리 중에 pattern match 하는 함수가 있는 
 * 듯.. 쩝... 만들어 둔 후에 안거라서.... 쩝...
 *---------------------------------------------------------*/
int IGIisMatch(char s[], char key[]);




/*=======================================================
 * 함수명 : power
 * 기능   : 거듭 제곱에 대한 값을 구한다.
 * 반환   : 정상일 때, 거듭제곱한 값 (1 이상의 값)
 *          오류일 때, -1
 *
 * 사용예)     rt = power( 5, 2 );
 *               rt -> 5 X 5  = 25
 *----------------------------------------------------*/
int IGIgetPower(int base, int times);



/*=====================================================
 * 함수명 : IGIsleep
 * 인수   : sleep할 시간 값(microsec)
 * 기능   : usleep 함수와 비슷한 함수로, select를 
 *          이용하여 구현
 * 반환   : 없음
 * 사용예 :  IGIsleep(500);  <- 0.5초 sleep
 *---------------------------------------------------*/
void IGIsleep(long usec);



int isMatch(char *code, int cnt, ...);


int isExistFile(char *fname, int mode);

/*-------------------------------
 * 파일이 잠겨있는지 확인하고 잠겨 있지 않으면
 * 잠금을 얻고 
 * 잠겨 있을경우 잠김이 풀릴때까지 기다린다(F_SETLKW) 
 *---------------------------------------------*/
int fd_lock(int fd);

/*-------------------------------
 * 파일 잠금을 얻은후 모든 작업이 끝난다면 
 * 파일 잠금을 돌려준다. 
 *------------------------------*/
int fd_unlock(int fd);

#ifndef _WIN32
long GetFileSize(char *fname);
#endif



/**----------------------------------------------------------------------
 * 함수명: getdatestr
 * 인수 : 없음
 * 반환 : 현재 일자를 문자열을 반환 (YYYYMMDD형태)
 * 기능 : 상동
 *------------------------------------------------------------------------*/
char *getdatestr();

/**----------------------------------------------------------------------
 * 함수명: getdatestrF
 * 인수 : 없음
 * 반환 : 현재 일자를 문자열을 반환 (YYYY/MM/DD형태)
 * 기능 : 상동
 *------------------------------------------------------------------------*/
char *getdatestrF();
char *getdatestrF2();

/**----------------------------------------------------------------------
 * 함수명: gettimestrF
 * 인수 : 없음
 * 반환 : 현재 시간을 문자열을 반환 (HH:MM:SS형태)
 * 기능 : 상동
 *------------------------------------------------------------------------*/
char *gettimestrF();

#endif


