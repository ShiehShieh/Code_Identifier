var
  a:array[1..10000]of integer;
  m,n,i:integer;
procedure martian;
  var i,j,e,w:integer;
  begin
    i:=n;
    j:=n;
    while a[i-1]>a[i] do dec(i);//找i值
    while a[j]<a[i-1] do dec(j);//找j值
    e:=a[i-1];a[i-1]:=a[j];a[j]:=e;
    w:=i;
    for i:=n downto (n-w+1) div 2+w do//翻转
      begin
        e:=a[i];a[i]:=a[w];a[w]:=e;
        inc(w);
      end;
  end;
begin
  readln(n);readln(m);
  for i:=1 to n do
    read(a[i]);//读入数据
  for i:=1 to m do
    martian;//掉过程
  for i:=1 to n do//输出程序
    write(a[i]);
end.
