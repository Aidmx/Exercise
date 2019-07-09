﻿#pragma once

/*
求证: 满节点个数+1等于叶子节点个数.
N = 节点个数  F = 满节点个数 H = 一个子节点个数 L = 叶子节点
由4.4 可知 N + 1 = 2L + H
证明F+1 = L
答： N = F + H + L；
 由 N + 1 = 2L + H 可推 :L = (N + 1 - H)/2 代入 N = F + H + L 
 得到 N - 1 = 2F + H；
 由 N + 1 = 2L + H 可推 :H = N+1-2L 代入
 得到 F + 1 = L;

*/

