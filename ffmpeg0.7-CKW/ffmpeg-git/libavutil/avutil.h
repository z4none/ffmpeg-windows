/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

//****************************************************************************//
//libavutil\avutil.h
//	libavutil.h的入口头文件，所有外部调用的第一站
//学习的地方：
//1.整体的版本宏定义是非常有趣的，值得好好学习：
//附录：
//****************************************************************************//

#ifndef AVUTIL_AVUTIL_H
#define AVUTIL_AVUTIL_H

#include "libavutil/attributes.h"
#include "libavutil/rational.h"
/**
 * @file
 * external API header
 */

//需要解决的疑问？
//"#"与"##"到底是什么样的问题所在？
#define AV_STRINGIFY(s)         AV_TOSTRING(s)
#define AV_TOSTRING(s) #s

#define AV_GLUE(a, b) a ## b
#define AV_JOIN(a, b) AV_GLUE(a, b)

#define AV_PRAGMA(s) _Pragma(#s)

#define AV_VERSION_INT(a, b, c) (a<<16 | b<<8 | c)
#define AV_VERSION_DOT(a, b, c) a ##.## b ##.## c
#define AV_VERSION(a, b, c) AV_VERSION_DOT(a, b, c)

#define LIBAVUTIL_VERSION_MAJOR 50
#define LIBAVUTIL_VERSION_MINOR 40
#define LIBAVUTIL_VERSION_MICRO  1

#define LIBAVUTIL_VERSION_INT   AV_VERSION_INT(LIBAVUTIL_VERSION_MAJOR, \
                                               LIBAVUTIL_VERSION_MINOR, \
                                               LIBAVUTIL_VERSION_MICRO)
#define LIBAVUTIL_VERSION       AV_VERSION(LIBAVUTIL_VERSION_MAJOR,     \
                                           LIBAVUTIL_VERSION_MINOR,     \
                                           LIBAVUTIL_VERSION_MICRO)
#define LIBAVUTIL_BUILD         LIBAVUTIL_VERSION_INT

#define LIBAVUTIL_IDENT         "Lavu" AV_STRINGIFY(LIBAVUTIL_VERSION)

/**
 * Those FF_API_* defines are not part of public API.
 * They may change, break or disappear at any time.
 */
#ifndef FF_API_OLD_EVAL_NAMES
#define FF_API_OLD_EVAL_NAMES (LIBAVUTIL_VERSION_MAJOR < 51)
#endif

/**
 * Return the LIBAVUTIL_VERSION_INT constant.
 */
FFMPEGLIB_API unsigned avutil_version(void);

/**
 * Return the libavutil build-time configuration.
 */
FFMPEGLIB_API const char *avutil_configuration(void);

/**
 * Return the libavutil license.
 */
FFMPEGLIB_API const char *avutil_license(void);

//sleep in Windows
#ifdef WIN32
FFMPEGLIB_API void usleep(const long int mirSec);
#endif

enum AVMediaType
{
    AVMEDIA_TYPE_UNKNOWN = -1,
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA,
    AVMEDIA_TYPE_SUBTITLE,
    AVMEDIA_TYPE_ATTACHMENT,
    AVMEDIA_TYPE_NB
};

#define FF_LAMBDA_SHIFT 7
#define FF_LAMBDA_SCALE (1<<FF_LAMBDA_SHIFT)
#define FF_QP2LAMBDA 118 ///< factor to convert from H.263 QP to lambda
#define FF_LAMBDA_MAX (256*128-1)

#define FF_QUALITY_SCALE FF_LAMBDA_SCALE //FIXME maybe remove

#define AV_NOPTS_VALUE          INT64_C(0x8000000000000000)
#define AV_TIME_BASE            1000000
#define AV_TIME_BASE_Q          av_getTimebase_Q()//(AVRational){1, AV_TIME_BASE}


FFMPEGLIB_API AVRational av_getTimebase_Q(void);
/**
 * Those FF_API_* defines are not part of public API.
 * They may change, break or disappear at any time.
 */
#ifndef FF_API_OLD_IMAGE_NAMES
#define FF_API_OLD_IMAGE_NAMES (LIBAVUTIL_VERSION_MAJOR < 51)
#endif

#include "common.h"
#include "error.h"
#include "mathematics.h"
#include "rational.h"
#include "intfloat_readwrite.h"
#include "log.h"
#include "pixfmt.h"

#endif /* AVUTIL_AVUTIL_H */
