var a:array[1..20,0..200]of longint;
    b:array[1..20,1..2]of longint;
    c:array[1..20,0..200]of boolean;
    i,j,k,l1,l2,ll,kk,n,m,ans:longint;
begin
  readln(n,m);
  for i:=1 to m do
    readln(b[i,1],b[i,2]);
  fillchar(c,sizeof(c),false);
  for i:=1 to m do
    c[i,0]:=true;
  for i:=1 to n do
    begin
      for j:=1 to m do
          if c[j,a[j,0]] then begin
                 l1:=a[j,0];
                 inc(a[j,0]);
                 l2:=a[j,0]; ll:=1; kk:=1;
                 for k:=1 to b[j,2] do
                   begin
                     ll:=ll*l1;
                     kk:=kk*l2;
                   end;
                 a[j,a[j,0]]:=(kk-ll)*b[j,1];
                                           end;
      l1:=maxlongint;
      for j:=1 to m do
        if a[j,a[j,0]]<l1 then begin l2:=j; l1:=a[j,a[j,0]]; end;
      c[l2,a[l2,0]]:=true;
    end;
  for i:=1 to m do
    begin
      for j:=1 to a[i,0]-1 do
        ans:=ans+a[i,j];
    end;
  writeln(ans+a[l2,a[l2,0]]);
end.





