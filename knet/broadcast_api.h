/*
 * Copyright (c) 2014-2015, dennis wang
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL dennis wang BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef BROADCAST_API_H
#define BROADCAST_API_H

#include "config.h"

/*
 * 创建广播域
 * @return broadcast_t实例
 */
broadcast_t* broadcast_create();

/*
 * 销毁广播域
 * @param broadcast broadcast_t实例
 */
void broadcast_destroy(broadcast_t* broadcast);

/*
 * 加入广播域
 * 加入成功会生成一个新的引用
 * @param broadcast broadcast_t实例
 * @param channel_ref channel_ref_t
 * @return channel_ref_t实例，新的在广播域内的引用
 */
channel_ref_t* broadcast_join(broadcast_t* broadcast, channel_ref_t* channel_ref);

/*
 * 离开广播域
 * @param broadcast broadcast_t实例
 * @param channel_ref channel_ref_t实例，由broadcast_join()返回
 * @retval error_ok 成功
 * @retval 其他 失败
 */
int broadcast_leave(broadcast_t* broadcast, channel_ref_t* channel_ref);

/*
 * 取得广播域内管道数量
 * @param broadcast broadcast_t实例
 * @return 管道数量
 */
int broadcast_get_count(broadcast_t* broadcast);

/*
 * 广播
 * @param broadcast broadcast_t实例
 * @param buffer 缓冲区指针
 * @param size 缓冲区长度
 * @return 发送成功管道的数量
 */
int broadcast_write(broadcast_t* broadcast, char* buffer, uint32_t size);

#endif /* BROADCAST_API_H */
