Problem:    lp_problem2
Rows:       7
Columns:    5 (4 integer, 4 binary)
Non-zeros:  20
Status:     INTEGER OPTIMAL
Objective:  z = 3 (MAXimum)

   No.   Row name        Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 z                           3                             
     2 con1                       -1                          -0 
     3 con2                        0                          -0 
     4 con3                       -1                          -0 
     5 con4                        0                          -0 
     6 con5                        0                          -0 
     7 con6                       -1                          -0 

   No. Column name       Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 x1           *              1             0             1 
     2 x2           *              1             0             1 
     3 x3           *              1             0             1 
     4 x4           *              0             0             1 
     5 m                           2             2             = 

Integer feasibility conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
