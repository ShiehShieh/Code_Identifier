var       x,y:array[0..100000]of dword;
          a:array[0..100000]of dword;
          tot:dword;
          n,m,xx,yy,xxx,yyy,k,sum,i:dword;
begin
          readln(n);
	  tot:=0;
          repeat
           read(m);
           case m of
           1:begin
             readln(xx,yy,k);
             inc(tot);
             x[tot]:=xx;
             y[tot]:=yy;
             inc(a[tot],k);
             end;
           2:begin
             sum:=0;
             readln(xx,yy,xxx,yyy);
             for i:=1to tot do
              if (x[i]>=xx)and(x[i]<=xxx)and(y[i]>=yy)and(y[i]<=yyy)
               then inc(sum,a[i]);
             writeln(sum);
             end;
           end;
          until m=3;
end.
