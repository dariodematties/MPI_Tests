## Tests performed on KNL 7210 nodes @ JLSE (jlse.anl.gov)

### 1 node

```
[srizzi@knl08 MPI_Tests]$ mpiexec -n 1 ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (438.523s), (19976kB)
  SuperSet::computeSuperSetAverage  computation = (438.522s), (19976kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (9.39369e-05s), (19976kB)
=================================================================
```

### 2 nodes

```
[srizzi@knl05 MPI_Tests]$ mpiexec -n 2 -f $COBALT_NODEFILE ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (152.922s), (15596kB)
  SuperSet::computeSuperSetAverage  computation = (150.507s), (15344kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (2.41145s), (15596kB)
=================================================================

=================================================================
  Time/Memory log (rank: 1) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (152.925s), (11816kB)
  SuperSet::computeSuperSetAverage  computation = (152.92s), (11676kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00158596s), (11676kB)
=================================================================
```

### 4 nodes

```
[srizzi@knl06 MPI_Tests]$ mpiexec -n 4 -f $COBALT_NODEFILE ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (47.3876s), (9556kB)
  SuperSet::computeSuperSetAverage  computation = (47.0942s), (9476kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.287891s), (9556kB)
=================================================================

=================================================================
  Time/Memory log (rank: 1) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (47.394s), (9552kB)
  SuperSet::computeSuperSetAverage  computation = (47.3844s), (9472kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00331283s), (9552kB)
=================================================================

=================================================================
  Time/Memory log (rank: 2) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (47.3997s), (13484kB)
  SuperSet::computeSuperSetAverage  computation = (41.6676s), (13232kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (5.45098s), (13484kB)
=================================================================

=================================================================
  Time/Memory log (rank: 3) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (47.4004s), (9396kB)
  SuperSet::computeSuperSetAverage  computation = (40.7072s), (9140kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.961778s), (9396kB)
=================================================================
```

