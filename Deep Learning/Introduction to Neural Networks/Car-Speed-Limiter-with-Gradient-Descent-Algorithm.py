#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sun Dec 16 16:37:13 2018

@author: tajir
"""

import numpy as np
import random

#constants
SPEED_LIMIT = 60.000000000
eps = 0.000000001

#variables
data = []

def sigmoid(x):
    return (1 / (1 + np.exp(-x)))

def train(limit):
    learn_rate = 0.3

    for x in data:
        speed = x[0]
        y = x[1]
        
        #======================= Need to change here ====================

        y_hat = sigmoid(())

        limit += learn_rate*(y - y_hat)*abs(speed-limit)
    return limit

limit = random.uniform(1.0 , 180.0)

for i in range(1,400) :
    limit = train(limit)
    speed = input()
    verdict = ((speed - SPEED_LIMIT) < eps)
    print "New Limit : ",limit
    if ((limit-speed) > eps):
        print "Inside Speed Limit"
    else :
        print "Outside Speed Limit. Blocked"
    data.append((speed , verdict))
    print(data)
    print "\n"
