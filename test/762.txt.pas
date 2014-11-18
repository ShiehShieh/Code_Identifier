var
      now,sum,num,n,m,i,j,t,temp,k:longint;
      r:array[0..1] of longint;
      list:array[0..1,0..1024] of longint;
      kk:array[0..1024] of longint;
      a:array[0..101,0..11] of longint;
procedure bfs;
begin
    now:=0;  r[now]:=1;  list[0,1]:=num;
     repeat
        now:=1-now;   r[now]:=0;  inc(sum);
        for I:=1 to r[1-now] do
          for j:=1 to m do
           begin
              temp:=list[1-now,i];
             for k:=1 to n do
              begin
                if a[j,k]=-1 then
                 temp:=temp or (1 shl (n-k));
                if a[j,k]=1 then
                 temp:=temp and not (1 shl (n-k));
              end;
           if temp=0 then
             begin
                writeln(sum);
                halt;
             end;
           if kk[temp]=0 then
             begin
                inc(r[now]);
                list[now,r[now]]:=temp;
                kk[temp]:=1;
             end;
           end;
       if r[now]=0 then begin  writeln('The patient will be dead.');
                               halt;
                        end;
      until 1<>1;
end;
begin
      readln(n,m);
      fillchar(a,sizeof(a),0);
     for i:=1 to m do
       for J:=1 to n do
         read(a[i,j]);
    t:=1;
     for i:=1 to n do
      begin
       num:=num+t;
       t:=t*2;
      end;
     kk[num]:=1;
    bfs;
end.


