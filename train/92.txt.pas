var i,j,l1,k,t,l2,tt,l3,f:longint;
    s:ansistring;
    a,b,d:array[0..2000] of longint;
begin
    while not eof do
    begin
    fillchar(a,sizeof(a),0);
    fillchar(b,sizeof(b),0);
    readln(s); tt:=0; f:=0;
    while s[1]=' ' do delete(s,1,1); l1:=0;
    for i:=1 to length(s) do
    if s[i]='.' then tt:=l1
    else if s[i]=' ' then break
    else begin l1:=l1+1; a[l1]:=ord(s[i])-48; end;
    delete(s,1,i);
    while s[1]=' ' do delete(s,1,1);
    val(s,k,j); l2:=l1;
    for i:=1 to l2 div 2 do
    begin
    t:=a[i]; a[i]:=a[l2-i+1]; a[l2-i+1]:=t;
    end; d:=a; tt:=l1-tt; l3:=tt;
    for t:=1 to k-1 do
    begin
    b:=d; l3:=l3+tt;
    fillchar(d,sizeof(d),0);
    for i:=1 to l2 do
    for j:=1 to l1 do
    d[i+j-1]:=d[i+j-1]+a[j]*b[i];
    l2:=l1+l2;
    for i:=1 to l2 do
    if d[i]>=10 then
    begin d[i+1]:=d[i+1]+d[i] div 10; d[i]:=d[i] mod 10; end;
    if d[l2+1]>0 then l2:=l2+1;
    end;  s:='';
    for j:=l2 downto 1 do
    begin
    if j=l3 then s:=s+'.';
    s:=s+chr(d[j]+48);
    end;
    while s[1]='0' do delete(s,1,1);
    if pos('.',s)>0 then
    while s[length(s)]='0' do delete(s,length(s),1);
    if s[length(s)]='.' then delete(s,length(s),1);
    writeln(s);
    end;
end.



