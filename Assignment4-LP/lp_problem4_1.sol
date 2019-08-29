Problem:    lp_problem4
Rows:       6
Columns:    5 (5 integer, 5 binary)
Non-zeros:  11
Status:     INTEGER OPTIMAL
Objective:  z = 0 (MINimum)

   No.   Row name        Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 z                           0                             
     2 con1                        1             1             = 
     3 con2                        1             1             = 
     4 con3                        1             1             = 
     5 con4                        1             1             = 
     6 con5                        0                           1 

   No. Column name       Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 xij          *              0             0             1 
     2 xil          *              1             0             1 
     3 xkj          *              1             0             1 
     4 xkl          *              0             0             1 
     5 Sijkl        *              0             0             1 

Integer feasibility conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
