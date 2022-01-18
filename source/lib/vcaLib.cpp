/*****************************************************************************
 * Copyright (C) 2022 Christian Doppler Laboratory ATHENA
 *
 * Authors: Vignesh V Menon <vignesh.menon@aau.at>
 *          Christian Feldmann <christian.feldmann@bitmovin.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.
 *****************************************************************************/

#include "vcaLib.h"
#include "analyzer/Analyzer.h"

DLL_PUBLIC vca_analyzer *vca_analyzer_open(vca_param param)
{
    return new vca::Analyzer(param);
}

DLL_PUBLIC vca_result vca_analyzer_push(vca_analyzer *enc, vca_frame *frame)
{
    if (enc == nullptr)
        return vca_result::VCA_ERROR;

    auto analyzer = (vca::Analyzer *) enc;
    if (analyzer == nullptr)
        return vca_result::VCA_ERROR;

    return analyzer->pushFrame(frame);
}

DLL_PUBLIC bool vca_result_available(vca_analyzer *enc)
{
    auto analyzer = (vca::Analyzer *) (enc);
    return analyzer->resultAvailable();
}

DLL_PUBLIC vca_result vca_analyzer_pull_frame_result(vca_analyzer *enc, vca_frame_results *result)
{
    if (enc == nullptr || result == nullptr)
        return vca_result::VCA_ERROR;

    auto analyzer = (vca::Analyzer *) (enc);
    if (analyzer == nullptr)
        return vca_result::VCA_ERROR;

    return analyzer->pullResult(result);
}

DLL_PUBLIC void vca_analyzer_close(vca_analyzer *enc)
{
    auto analyzer = (vca::Analyzer *) enc;
    delete analyzer;
}

DLL_PUBLIC void vca_analyzer_shot_detect(vca_analyzer *enc) {}
