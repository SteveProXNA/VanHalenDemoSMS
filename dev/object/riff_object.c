#include "riff_object.h"
#include "..\banks\bank16.h"
#include "..\banks\bank17.h"
#include "..\banks\bank18.h"
#include "..\banks\bank19.h"
#include "..\banks\bank20.h"
#include "..\banks\bank21.h"
#include "..\banks\bank22.h"
#include "..\banks\bank23.h"
#include "..\banks\bank24.h"
#include "..\banks\bank25.h"
#include "..\banks\bank26.h"
#include "..\banks\bank27.h"
#include "..\banks\bank28.h"
#include "..\banks\bank29.h"
#include "..\banks\bank30.h"
#include "..\banks\bank31.h"
#include "..\banks\bank32.h"
#include "..\banks\bank33.h"
#include "..\banks\bank34.h"
#include "..\banks\bank35.h"
#include "..\banks\bank36.h"
#include "..\banks\bank37.h"
#include "..\banks\bank38.h"
#include "..\banks\bank39.h"
#include "..\banks\bank40.h"
#include "..\banks\bank41.h"
#include "..\banks\bank42.h"
#include "..\banks\bank43.h"
#include "..\banks\bank44.h"
#include "..\banks\bank45.h"
#include "..\banks\bank46.h"
#include "..\banks\bank47.h"
#include "..\banks\bank48.h"
#include "..\banks\bank49.h"
#include "..\banks\bank50.h"
#include "..\banks\bank51.h"
#include "..\banks\bank52.h"
#include "..\banks\bank53.h"
#include "..\banks\bank54.h"
#include "..\banks\bank55.h"
#include "..\banks\bank56.h"
#include "..\banks\bank57.h"
#include "..\banks\bank58.h"
#include "..\banks\bank59.h"
#include "..\banks\bank60.h"
#include "..\banks\bank61.h"
#include "..\banks\bank62.h"
#include "..\banks\bank63.h"

const unsigned char *riff_sample_data[] =
{
	Riff_1978_01_wav_pcmenc,
	Riff_1978_02_wav_pcmenc,
	Riff_1978_03_wav_pcmenc,
	Riff_1978_04_wav_pcmenc,
	Riff_1979_01_wav_pcmenc,
	Riff_1979_02_wav_pcmenc,
	Riff_1979_03_wav_pcmenc,
	Riff_1979_04_wav_pcmenc,
	Riff_1980_01_wav_pcmenc,
	Riff_1980_02_wav_pcmenc,
	Riff_1980_03_wav_pcmenc,
	Riff_1980_04_wav_pcmenc,
	Riff_1981_01_wav_pcmenc,
	Riff_1981_02_wav_pcmenc,
	Riff_1981_03_wav_pcmenc,
	Riff_1981_04_wav_pcmenc,
	Riff_1982_01_wav_pcmenc,
	Riff_1982_02_wav_pcmenc,
	Riff_1982_03_wav_pcmenc,
	Riff_1982_04_wav_pcmenc,
	Riff_1984_01_wav_pcmenc,
	Riff_1984_02_wav_pcmenc,
	Riff_1984_03_wav_pcmenc,
	Riff_1984_04_wav_pcmenc,
	Riff_1986_01_wav_pcmenc,
	Riff_1986_02_wav_pcmenc,
	Riff_1986_03_wav_pcmenc,
	Riff_1986_04_wav_pcmenc,
	Riff_1988_01_wav_pcmenc,
	Riff_1988_02_wav_pcmenc,
	Riff_1988_03_wav_pcmenc,
	Riff_1988_04_wav_pcmenc,
	Riff_1991_01_wav_pcmenc,
	Riff_1991_02_wav_pcmenc,
	Riff_1991_03_wav_pcmenc,
	Riff_1991_04_wav_pcmenc,
	Riff_1995_01_wav_pcmenc,
	Riff_1995_02_wav_pcmenc,
	Riff_1995_03_wav_pcmenc,
	Riff_1995_04_wav_pcmenc,
	Riff_1998_01_wav_pcmenc,
	Riff_1998_02_wav_pcmenc,
	Riff_1998_03_wav_pcmenc,
	Riff_1998_04_wav_pcmenc,
	Riff_2012_01_wav_pcmenc,
	Riff_2012_02_wav_pcmenc,
	Riff_2012_03_wav_pcmenc,
	Riff_2012_04_wav_pcmenc,
};

const unsigned char riff_sample_bank[] =
{
	Riff_1978_01_wav_pcmenc_bank,
	Riff_1978_02_wav_pcmenc_bank,
	Riff_1978_03_wav_pcmenc_bank,
	Riff_1978_04_wav_pcmenc_bank,
	Riff_1979_01_wav_pcmenc_bank,
	Riff_1979_02_wav_pcmenc_bank,
	Riff_1979_03_wav_pcmenc_bank,
	Riff_1979_04_wav_pcmenc_bank,
	Riff_1980_01_wav_pcmenc_bank,
	Riff_1980_02_wav_pcmenc_bank,
	Riff_1980_03_wav_pcmenc_bank,
	Riff_1980_04_wav_pcmenc_bank,
	Riff_1981_01_wav_pcmenc_bank,
	Riff_1981_02_wav_pcmenc_bank,
	Riff_1981_03_wav_pcmenc_bank,
	Riff_1981_04_wav_pcmenc_bank,
	Riff_1982_01_wav_pcmenc_bank,
	Riff_1982_02_wav_pcmenc_bank,
	Riff_1982_03_wav_pcmenc_bank,
	Riff_1982_04_wav_pcmenc_bank,
	Riff_1984_01_wav_pcmenc_bank,
	Riff_1984_02_wav_pcmenc_bank,
	Riff_1984_03_wav_pcmenc_bank,
	Riff_1984_04_wav_pcmenc_bank,
	Riff_1986_01_wav_pcmenc_bank,
	Riff_1986_02_wav_pcmenc_bank,
	Riff_1986_03_wav_pcmenc_bank,
	Riff_1986_04_wav_pcmenc_bank,
	Riff_1988_01_wav_pcmenc_bank,
	Riff_1988_02_wav_pcmenc_bank,
	Riff_1988_03_wav_pcmenc_bank,
	Riff_1988_04_wav_pcmenc_bank,
	Riff_1991_01_wav_pcmenc_bank,
	Riff_1991_02_wav_pcmenc_bank,
	Riff_1991_03_wav_pcmenc_bank,
	Riff_1991_04_wav_pcmenc_bank,
	Riff_1995_01_wav_pcmenc_bank,
	Riff_1995_02_wav_pcmenc_bank,
	Riff_1995_03_wav_pcmenc_bank,
	Riff_1995_04_wav_pcmenc_bank,
	Riff_1998_01_wav_pcmenc_bank,
	Riff_1998_02_wav_pcmenc_bank,
	Riff_1998_03_wav_pcmenc_bank,
	Riff_1998_04_wav_pcmenc_bank,
	Riff_2012_01_wav_pcmenc_bank,
	Riff_2012_02_wav_pcmenc_bank,
	Riff_2012_03_wav_pcmenc_bank,
	Riff_2012_04_wav_pcmenc_bank,
};