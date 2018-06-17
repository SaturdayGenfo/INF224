# -*- coding: utf-8 -*-
"""
Created on Sun Jun 17 23:36:26 2018

@author: leello
"""

import numpy as np

r = 1
lmbda = 5
pI = 0.8
alpha = 1
mu1 = 0.1
mu2 = 0.2

def discreet(x0, p, tmax, N):
    
    q1 = lambda n1, n2 : N*r + N*lmbda*pI*n1/(n1+n2)
    q2 = lambda n1, n2 : mu1*n1
    q3 = lambda n1, n2 : alpha*p*n2*n1/(n1+n2)
    q4 = lambda n1, n2 : N*lmbda*(1-pI*n1/(n1+n2))
    q5 = lambda n1, n2 : mu2*n2
    
    qlst = [q1, q2, q3, q4, q5]
    transitions = [np.array(tr) for tr in [[1, 0], [-1, 0], [1, -1], [0,1], [0, -1]]]
    
    
    sauts = []
    x = N*x0
    
    Xs = [x]
    tau = [np.random.exponential(1/q(*x)) for q in qlst]
    nxt_t = min(tau)
    while nxt_t < tmax:
        sauts.append(nxt_t)
        x = x + transitions[np.argmin(tau)]
        tau = [np.random.exponential(1/q(*x)) for q in qlst]
        nxt_t += min(tau)
        Xs.append(x)
    
    f = lambda x: x[0]/(x[1] + x[0])
    return np.average([f(X) for X in Xs])

x0 = np.array([50, 50])
plst = np.linspace(0, 0.6 , 40)
data = []
for pi in plst:
    d = []
    for k in range(10):
        d.append(discreet(x0, pi, 150, 100))
    print(pi, np.average(d))
    data.append([np.average(d), np.std(d)])

print(data)