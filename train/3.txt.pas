program cake;
var
  n,m,min,ss,vv1,vv2,r,h:integer;

procedure search(n,k,i,j,s:integer);
var ii,x,y:integer;
begin
  ss:=k*k; vv1:=0; vv2:=0;
  for ii:=1 to k do begin
                    ss:=ss+2*ii*ii;
                    vv1:=vv1+ii*ii*ii;
                    vv2:=vv2+(i-ii)*(i-ii)*(j-ii);
                    end;
  if (n<vv1) or (n>vv2) then exit;
  if s+ss>min then exit
              else if k=0 then begin s:=s+i*i;
                               if (s<min) and (n=0) then min:=s;
                               exit;end;
  for x:=i-1 downto k do
   for y:=j-1 downto k do
    search(n-x*x*y,k-1,x,y,s+i*i-x*x+2*x*y);
    end;
  begin
  readln(n);
  readln(m);
  min:=maxint;
  for r:=30 downto m do
   for h:=30 downto m do
  search(n-r*r*h,m-1,r,h,2*r*h);
  if min=maxint then write(0)
                else write(min);
  end.
