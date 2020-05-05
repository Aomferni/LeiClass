//
//  sound.h
//  TunderClass
//
//  Created by Amy Zhou on 2020/5/5.
//  Copyright © 2020 Amy Zhou. All rights reserved.
//

#ifndef sound_h
#define sound_h
int simplest_pcm16le_to_wave(const char *pcmpath, int channels, int sample_rate, const char *wavepath);

#endif /* sound_h */
