program dd;
  var
    n,m,i,j,max:longint;
    v,p:array[0..26]of longint;
    a:array[0..30100] of longint;

begin
  read(n,m);
  for i:=1 to m do begin
    read(v[i],p[i]);
    p[i]:=p[i]*v[i];
  end;
  fillchar(a,sizeof(a),0);

  for i:=1 to m do
    for j:=n downto v[i] do
      if a[j-v[i]]+p[i]>a[j] then a[j]:=a[j-v[i]]+p[i];

  max:=0;
  for i:=1 to n do
    if a[i]>max then max:=a[i];
  writeln(max);
end.
