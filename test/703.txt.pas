program chao;
var a:array[1..100]of longint;
    n,i,s,v,e:longint;

  begin
   readln(n);s:=0;e:=0;
   for i:=1 to n do
      begin
          read(a[i]);
          s:=s+a[i];
      end;
      v:=s div n;
   for i:=1 to n do
    if a[i]<>v then begin
                        a[i+1]:=a[i+1]-v+a[i];
                        a[i]:=v;
                        e:=e+1;
                   end;
   writeln(e);
  end.
