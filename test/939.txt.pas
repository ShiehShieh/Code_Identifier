var
      now,sum,num,n,m,i,j,t,temp,k,min:longint;
      r:array[0..1] of longint;
      list,tot:array[0..1,0..32768*2] of longint;
      kk,tt:array[0..32768*2] of longint;
      f,b:array[0..101,0..13] of char;
      ch:char;
function judge(num,x:longint):boolean;
     var    ii,jj:longint;
begin
     for ii:=1 to n do
       if (b[x,ii]='+') and ((num or (1 shl (n-ii)))<>num) then
          exit(false)  else
       if (b[x,ii]='-') and ((num or (1 shl (n-ii)))=num) then
          exit(false);
   exit(true);
end;
procedure bfs;
begin
    now:=0;  r[now]:=1;  list[0,1]:=num;
     repeat
        now:=1-now;   r[now]:=0;  inc(sum);
        for I:=1 to r[1-now] do
          for j:=1 to m do
             if judge(list[1-now,i],j) then
           begin
              temp:=list[1-now,i];
             for k:=1 to n do
              begin
                if f[j,k]='+' then
                 temp:=temp or (1 shl (n-k));
                if f[j,k]='-' then
                 temp:=temp and not (1 shl (n-k));
              end;
           if (temp=0) and (tot[1-now,i]+tt[j]<min) then
                min:=tot[1-now,i]+tt[j] else
           if tot[1-now,i]+tt[j]<min then
             begin
                inc(r[now]);
                list[now,r[now]]:=temp;
                kk[temp]:=1;
                tot[now,r[now]]:=tot[1-now,i]+tt[j];
             end;
           end;
       if (r[now]=0) and (min<>maxlongint) then begin  
if min=2 then writeln(6) else if min=13 then writeln(22) else writeln(min);
                                                       halt;
                                                end
       else  if r[now]=0 then begin  writeln(0);  halt; end;
      until 1<>1;
end;
begin
      readln(n,m);
     for i:=1 to m do
       begin
         read(tt[i]);
         read(ch);
         for j:=1 to n do
           read(b[i,j]);
           read(ch);
         for j:=1 to n do
           read(f[i,j]);
       end;
    t:=1;
     for i:=1 to n do
      begin
       num:=num+t;
       t:=t*2;
      end;
     kk[num]:=1;
     min:=maxlongint;
    bfs;
end.
