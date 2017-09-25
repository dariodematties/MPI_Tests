## Tests performed on KNL 7210 nodes @ JLSE (jlse.anl.gov)

## Results with GNU compiler and default optimizations


### Compiler

```
[srizzi@jlselogin1 testsJLSE]$ g++ --version
g++ (GCC) 4.8.5 20150623 (Red Hat 4.8.5-16)
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### MPI version

```
[srizzi@jlselogin1 MPI_Tests]$ cat setenv.sh 
export PATH=$PATH:/soft/libraries/mpi/mpich-gcc-3.1.4/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/soft/libraries/mpi/mpich-gcc-3.1.4/lib
```

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

<hr>

## Results with Intel compiler and default optimizations

### Compiler

```
[srizzi@jlselogin1 MPI_Tests]$ icpc --version
icpc (ICC) 18.0.0 20170811
Copyright (C) 1985-2017 Intel Corporation.  All rights reserved.
```

### MPI version

```
[srizzi@jlselogin1 MPI_Tests]$ mpiicpc --version
icpc (ICC) 18.0.0 20170811
Copyright (C) 1985-2017 Intel Corporation.  All rights reserved.
```

# 1 node

```
[srizzi@knl04 MPI_Tests]$ mpiexec -n 1 ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (84.3157s), (70512kB)
  SuperSet::computeSuperSetAverage  computation = (84.2989s), (70448kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.007622s), (70512kB)
=================================================================
```

# 2 nodes

```
[srizzi@knl05 MPI_Tests]$ mpiexec -n 2 -ppn 1 -f $COBALT_NODEFILE ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (34.2117s), (90652kB)
  SuperSet::computeSuperSetAverage  computation = (33.3526s), (90652kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.85787s), (90652kB)
=================================================================

=================================================================
  Time/Memory log (rank: 1) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (34.212s), (91080kB)
  SuperSet::computeSuperSetAverage  computation = (34.2069s), (91000kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00382304s), (91080kB)
=================================================================
```

# 4 nodes

```
[srizzi@knl04 MPI_Tests]$ mpiexec -n 4 -ppn 1 -f $COBALT_NODEFILE ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (19.749s), (92116kB)
  SuperSet::computeSuperSetAverage  computation = (16.3821s), (92044kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (3.36539s), (92116kB)
=================================================================

=================================================================
  Time/Memory log (rank: 1) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (19.7497s), (88224kB)
  SuperSet::computeSuperSetAverage  computation = (19.7478s), (88148kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000239134s), (88224kB)
=================================================================

=================================================================
  Time/Memory log (rank: 2) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (19.7497s), (88468kB)
  SuperSet::computeSuperSetAverage  computation = (19.6133s), (88380kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00022316s), (88468kB)
=================================================================

=================================================================
  Time/Memory log (rank: 3) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (19.7493s), (87320kB)
  SuperSet::computeSuperSetAverage  computation = (16.3526s), (87076kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00368905s), (87320kB)
=================================================================
```

# 8 nodes

```
[srizzi@knl08 MPI_Tests]$ mpiexec -n 8 -ppn 1 -f $COBALT_NODEFILE ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (9.97534s), (90688kB)
  SuperSet::computeSuperSetAverage  computation = (8.41416s), (90580kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (1.55965s), (90688kB)
=================================================================

=================================================================
  Time/Memory log (rank: 1) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (9.9752s), (86812kB)
  SuperSet::computeSuperSetAverage  computation = (8.35624s), (86744kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000203133s), (86812kB)
=================================================================

=================================================================
  Time/Memory log (rank: 2) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (9.97536s), (88104kB)
  SuperSet::computeSuperSetAverage  computation = (8.30516s), (88104kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00011301s), (88104kB)
=================================================================

=================================================================
  Time/Memory log (rank: 3) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (9.97481s), (84788kB)
  SuperSet::computeSuperSetAverage  computation = (9.97283s), (84688kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000243902s), (84688kB)
=================================================================

=================================================================
  Time/Memory log (rank: 4) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (9.97498s), (86668kB)
  SuperSet::computeSuperSetAverage  computation = (9.28216s), (86596kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00032115s), (86668kB)
=================================================================

=================================================================
  Time/Memory log (rank: 5) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (9.97534s), (86232kB)
  SuperSet::computeSuperSetAverage  computation = (7.66757s), (85984kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00011611s), (86232kB)
=================================================================

=================================================================
  Time/Memory log (rank: 6) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (9.97435s), (88200kB)
  SuperSet::computeSuperSetAverage  computation = (7.71258s), (87948kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00339103s), (88200kB)
=================================================================

=================================================================
  Time/Memory log (rank: 7) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (9.97428s), (86228kB)
  SuperSet::computeSuperSetAverage  computation = (8.14562s), (85988kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.0030489s), (85988kB)
=================================================================
```


<hr>

## Results with Intel compiler -O3 and -xmic-avx512


### Compiler

```
[srizzi@jlselogin1 MPI_Tests]$ icpc --version
icpc (ICC) 18.0.0 20170811
Copyright (C) 1985-2017 Intel Corporation.  All rights reserved.
```

### MPI version

```
[srizzi@jlselogin1 MPI_Tests]$ mpiicpc --version
icpc (ICC) 18.0.0 20170811
Copyright (C) 1985-2017 Intel Corporation.  All rights reserved.
```

### 1 node

```
[srizzi@knl04 MPI_Tests]$ mpiexec -n 1  ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (82.4751s), (70752kB)
  SuperSet::computeSuperSetAverage  computation = (82.473s), (70688kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000128984s), (70752kB)
=================================================================
```

### 2 nodes

```
[srizzi@knl05 MPI_Tests]$ mpiexec -n 2 -ppn 1 -f $COBALT_NODEFILE ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (40.7209s), (89288kB)
  SuperSet::computeSuperSetAverage  computation = (34.7814s), (89052kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (5.93826s), (89288kB)
=================================================================

=================================================================
  Time/Memory log (rank: 1) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (40.7189s), (91468kB)
  SuperSet::computeSuperSetAverage  computation = (40.717s), (91364kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000247002s), (91468kB)
=================================================================
```

### 4 nodes

```
[srizzi@knl04 MPI_Tests]$ mpiexec -n 4 -ppn 1 -f $COBALT_NODEFILE ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (19.6816s), (88428kB)
  SuperSet::computeSuperSetAverage  computation = (16.4799s), (88324kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (3.20029s), (88428kB)
=================================================================

=================================================================
  Time/Memory log (rank: 1) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (19.6793s), (88320kB)
  SuperSet::computeSuperSetAverage  computation = (19.6773s), (88252kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000273943s), (88320kB)
=================================================================

=================================================================
  Time/Memory log (rank: 2) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (19.6797s), (87360kB)
  SuperSet::computeSuperSetAverage  computation = (17.2139s), (87128kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00412488s), (87360kB)
=================================================================

=================================================================
  Time/Memory log (rank: 3) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (19.6814s), (87352kB)
  SuperSet::computeSuperSetAverage  computation = (16.4875s), (87092kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000118017s), (87092kB)
=================================================================
```

### 8 nodes

```
[srizzi@knl08 MPI_Tests]$ mpiexec -n 8 -ppn 1 -f $COBALT_NODEFILE ./Test 100 10000 100 4.4
Average is: 4.4

=================================================================
  Time/Memory log (rank: 0) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (10.0389s), (86320kB)
  SuperSet::computeSuperSetAverage  computation = (8.44468s), (86080kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (1.59274s), (86320kB)
=================================================================

=================================================================
  Time/Memory log (rank: 1) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (10.0388s), (86832kB)
  SuperSet::computeSuperSetAverage  computation = (8.35875s), (86728kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00917912s), (86728kB)
=================================================================

=================================================================
  Time/Memory log (rank: 2) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (10.0384s), (84276kB)
  SuperSet::computeSuperSetAverage  computation = (8.51413s), (84036kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000114918s), (84276kB)
=================================================================

=================================================================
  Time/Memory log (rank: 3) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (10.0381s), (86848kB)
  SuperSet::computeSuperSetAverage  computation = (10.0361s), (86748kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000252008s), (86748kB)
=================================================================

=================================================================
  Time/Memory log (rank: 4) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (10.0381s), (88644kB)
  SuperSet::computeSuperSetAverage  computation = (9.29755s), (88520kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000365973s), (88644kB)
=================================================================

=================================================================
  Time/Memory log (rank: 5) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (10.0389s), (88068kB)
  SuperSet::computeSuperSetAverage  computation = (7.7368s), (87816kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000110149s), (88068kB)
=================================================================

=================================================================
  Time/Memory log (rank: 6) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (10.0388s), (87780kB)
  SuperSet::computeSuperSetAverage  computation = (7.59388s), (87780kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.00011301s), (87780kB)
=================================================================

=================================================================
  Time/Memory log (rank: 7) 
  -------------------------------------------------------------
SuperSet::computeSuperSetAverage = (10.039s), (86240kB)
  SuperSet::computeSuperSetAverage  computation = (7.68425s), (85992kB)
  SuperSet::computeSuperSetAverage Inter-process comunication = (0.000113964s), (86240kB)
=================================================================
```

