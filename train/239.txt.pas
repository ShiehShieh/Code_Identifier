program P1327;

const

 maxn=5002;

var

 a:array[0..maxn] of char;

 opt:array[0..2,0..maxn] of longint;

 n,ans:longint;

function min(x,y:longint):longint;

 begin

  min:=y;

  if x<y then min:=x;

 end;

procedure main;

 var

  i,L,j,k0,k1,k2:longint;

 begin

  fillchar(opt,sizeof(opt),0);

  readln(n);

  for i:=1 to n do

   read(a[i]);

  k0:=0;

  k1:=1;

  k2:=2;

  for L:=1 to n-1 do

   begin

    for i:=1 to n-L do

     begin

      opt[k2,i]:=min(opt[k1,i],opt[k1,i+1])+1;

      if a[i]=a[i+L] then

       opt[k2,i]:=min(opt[k2,i],opt[k0,i+1]);

     end;

    j:=k0;

    k0:=k1;

    k1:=k2;

    k2:=j;

   end;

  writeln(opt[k1,1]);

 end;

begin

 main;

end.


