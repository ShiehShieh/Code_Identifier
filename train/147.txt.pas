var
  n,k,i:longint;
  w,bianhao:array[1..500000]of longint;
  e:array[1..10]of longint;
procedure kuaipai(head,tail:longint);
  var
    i,j,mid,step:longint;
  begin
    i:=head;
    j:=tail;
    mid:=w[(i+j)div 2];
    repeat
      while w[i]>mid do inc(i);
      while w[j]<mid do dec(j);
      if i<=j
        then begin
          step:=w[i];
          w[i]:=w[j];
          w[j]:=step;
          step:=bianhao[i];
          bianhao[i]:=bianhao[j];
          bianhao[j]:=step;
          inc(i);
          dec(j);
        end;
    until i>j;
    if i<tail then kuaipai(i,tail);
    if j>head then kuaipai(head,j);
  end;
procedure paixu(j:longint);
  var
    st:longint;
  begin
    while w[i]=w[j+1] do
      begin
        if bianhao[i]>bianhao[j+1]
          then begin
            st:=bianhao[i];
            bianhao[i]:=bianhao[j+1];
            bianhao[j+1]:=st;
          end;
        inc(j);
      end;
end;
begin
  readln(n,k);
  for i:=1 to 10 do
    read(e[i]);
  readln;
  for i:=1 to n do
    begin
      read(w[i]);
      bianhao[i]:=i;
    end;
  kuaipai(1,n);
  for i:=1 to n-1 do
    paixu(i);
  for i:=1 to n do
    w[i]:=w[i]+e[((i-1)mod 10)+1];
  kuaipai(1,n);
  for i:=1 to n-1 do
    paixu(i);
  for i:=1 to k do
    write(bianhao[i],' ');
end.





