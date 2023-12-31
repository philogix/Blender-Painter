/* SPDX-FileCopyrightText: 2020-2022 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

void main()
{
  vec4 prev_wpos = prevViewProjMatrix * vec4(prevWorldPos, 1.0);
  vec4 curr_wpos = currViewProjMatrix * vec4(currWorldPos, 1.0);
  vec4 next_wpos = nextViewProjMatrix * vec4(nextWorldPos, 1.0);

  vec2 prev_uv = (prev_wpos.xy / prev_wpos.w);
  vec2 curr_uv = (curr_wpos.xy / curr_wpos.w);
  vec2 next_uv = (next_wpos.xy / next_wpos.w);

  outData.xy = prev_uv - curr_uv;
  outData.zw = next_uv - curr_uv;

  /* Encode to unsigned normalized 16bit texture. */
  outData = outData * 0.5 + 0.5;
}
