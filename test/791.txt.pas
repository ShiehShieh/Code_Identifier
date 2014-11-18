var
    n,m,x1,x2,y1,y2:qword;
      i,j:longint;
       a:array[-1..1002,-1..1002] of qword;
begin
     readln(n,m);
     readln(x1,y1);
     readln(x2,y2);
       fillchar(a,sizeof(a),0);
         a[x1,y1]:=1;
          for i:=x1 to x2 do
           for j:=1 to m do
               if a[i,j]=0 then
                   a[i,j]:=a[i-2,j-1]+a[i-1,j-2]+a[i-1,j+2]+a[i-2,j+1];
                    if a[x2,y2]=0 then writeln('NO') else
                      begin
                        write(a[x2,y2]);writeln('00000000') end;
end.
