var
n,m,i,j,a1,b1,c1,min,path:integer;
 a:array [0..301,0..301] of integer;
  b:array [0..301] of boolean;
 procedure prim;
  var i1,ik,k,i:integer;
  begin
   for i1:=1 to n-2 do
    begin
     min:=maxint;
     for k:=1 to n do
      for i:=1 to n do
       if not (b[i]) and (b[k]) and (a[k,i]<min) then begin  min:=a[k,i];ik:=i;end;
         b[ik]:=true;
          if min>path then path:=min;
    end;
  end;
 begin
  read(n,m);
    for i:=1 to n do
     for j:=1 to n do
      a[i,j]:=maxint;
   for i:=1 to m do
    begin
     read(a1,b1,c1);
      a[a1,b1]:=c1;
      a[b1,a1]:=c1;
    end;
      b[1]:=true;
       min:=maxint;
       for i:=2 to n do
        if a[1,i]<min then begin  min:=a[1,i];j:=i;end;
         b[j]:=true;path:=min;
          prim;
         write(n-1,' ',path);
  end.


