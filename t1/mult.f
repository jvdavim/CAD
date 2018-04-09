      program mult
              integer, parameter::N=5
              integer::i, j
              double precision, dimension(:,:), allocatable::mat
              double precision, dimension(:), allocatable::vec, res
              real::start, finish, s
              allocate(mat(N+1,N+1),vec(N+1),res(N+1))
              do i=0,N
                 do j=0,N
                    mat(i,j)=rand(0)*1000
                 end do
                 vec(i)=rand(0)*1000
              end do
              call cpu_time(start)
              do i=0,N
                 s=0
                 do j=0,N
                    s=s+mat(i,j)*vec(j)
                 end do
                 res(i)=s
              end do
              call cpu_time(finish)
              print *,"Tempo: " ,finish-start, "s"
              deallocate(mat,vec,res)
              pause
      end program
