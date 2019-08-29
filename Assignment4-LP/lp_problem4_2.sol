Problem:    lp_problem4_2
Rows:       6
Columns:    6 (6 integer, 6 binary)
Non-zeros:  12
Status:     INTEGER OPTIMAL
Objective:  z = 0 (MINimum)

   No.   Row name        Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 z                           0                             
     2 con1                        1             1             = 
     3 con2                        1             1             = 
     4 con3                        1             1             = 
     5 con4                        1             1             = 
     6 con5                        0                           3 

   No. Column name       Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 xij          *              0             0             1 
     2 xil          *              1             0             1 
     3 xkj          *              1             0             1 
     4 xkl          *              0             0             1 
     5 pijl         *              0             0             1 
     6 pjil         *              0             0             1 

Integer feasibility conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
