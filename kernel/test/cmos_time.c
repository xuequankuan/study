#include <stdio.h>
#include <linux/bcd.h>
#include <linux/mc146818rtc.h>

void get_cmos_time(void)
{
	unsigned int year, mon, day, hour, min, sec;
	int i;

	/*  The Linux interpretation of the CMOS clock register contents:
	 *           * When the Update-In-Progress (UIP) flag goes from 1 to 0, the
		 *                    * RTC registers show the second which has precisely just started.
		 *                             * Let's hope other operating systems interpret the RTC the same way.
		 *                                      */
	   /*  read RTC exactly on falling edge of update flag */
	   for (i = 0 ; i < 1000000 ; i++) /*  may take up to 1 second... */
								  if (CMOS_READ(RTC_FREQ_SELECT) & RTC_UIP)
																 break;
						  for (i = 0 ; i < 1000000 ; i++) /*  must try at least 2.228 ms */
											 if (!(CMOS_READ(RTC_FREQ_SELECT) & RTC_UIP))
																		break;
								 do { /*  Isn't this overkill ? UIP above should guarantee consistency */
													sec = CMOS_READ(RTC_SECONDS);
																   min = CMOS_READ(RTC_MINUTES);
																			   hour = CMOS_READ(RTC_HOURS);
																						day = CMOS_READ(RTC_DAY_OF_MONTH);
																								 mon = CMOS_READ(RTC_MONTH);
																										 year = CMOS_READ(RTC_YEAR);
																										} while (sec != CMOS_READ(RTC_SECONDS));
								if (!(CMOS_READ(RTC_CONTROL) & RTC_DM_BINARY) || RTC_ALWAYS_BCD)
									 {
													 BCD_TO_BIN(sec);
																 BCD_TO_BIN(min);
																			 BCD_TO_BIN(hour);
																						 BCD_TO_BIN(day);
																									 BCD_TO_BIN(mon);
																												 BCD_TO_BIN(year);
																														   }
										 if ((year += 1900) < 1970)
															 year += 100;

												 printf("Date : %d-%d-%d %d:%d:%d\n", year, mon, day, hour, min, sec);

}

 

int main() {
	iopl(3);
	get_cmos_time();
}
