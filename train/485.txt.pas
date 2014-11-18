var
  i, j, k: longint;
  a: array[1..400,1..400] of real;
  p, x, y: array[1..400] of longint;
  w, dis: array[1..400] of real;
  n, m, t, cases, per, first, last: longint;
  b: array[1..100] of longint;

procedure init;
  var
    i, j, k, p: longint;
  begin
    for i := 1 to n do begin
      readln(x[4*i-3],y[4*i-3],x[4*i-2],y[4*i-2],x[4*i-1],y[4*i-1],b[i]);
      if (x[4*i-3]-x[4*i-1])*(x[4*i-2]-x[4*i-1])+(y[4*i-3]-y[4*i-1])*(y[4*i-2]-y[4*i-1])=0 then p := 1
      else if (x[4*i-3]-x[4*i-2])*(x[4*i-1]-x[4*i-2])+(y[4*i-3]-y[4*i-2])*(y[4*i-1]-y[4*i-2])=0 then p := 2
      else p := 3;
      k := 0;
      for j := 1 to 3 do begin
        if p=j then k := k-x[4*i-j]
        else k := k + x[4*i-j];
      end;
      x[4*i] := k;
      k := 0;
      for j := 1 to 3 do begin
        if p=j then k := k - y[4*i-j]
        else k := k + y[4*i-j];
      end;
      y[4*i] := k;
    end;
    for k := 1 to n do
      for i := 0 to 3 do begin
        for p := 1 to n do if k<>p then
          for j := 0 to 3 do a[4*k-i,4*p-j] := per * sqrt(sqr(x[4*k-i]-x[4*p-j])+sqr(y[4*k-i]-y[4*p-j]));
        for j := 0 to 3 do a[4*k-i,4*k-j] := b[k]*sqrt(sqr(x[4*k-i]-x[4*k-j])+sqr(y[4*k-i]-y[4*k-j]));
      end;
    for i := 0 to 3 do
      for j := 0 to 3 do begin
        a[4*first-i,4*first-j] := 0;
        a[4*last-i,4*last-j] := 0;
      end;
    first := 4 * first;
    last := 4 * last;
  end;
  
procedure ad_just(i: longint);
  var
    t: longint;
    t2: real;
  begin
    while i*2<=m do begin
      i := i * 2;
      if (i<m) and (w[i]>w[i+1]) then inc(i);
      if w[i]<w[i div 2] then begin
        t := p[i];
        p[i] := p[i div 2];
        p[i div 2] := t;
        t2 := w[i];
        w[i] := w[i div 2];
        w[i div 2] := t2;
      end else break;
    end;
  end;
  
procedure ad_just2(i: longint);
  var
    t: longint;
    t2: real;
  begin
    while i>1 do
      if w[i]<w[i div 2] then begin
        t := p[i];
        p[i] := p[i div 2];
        p[i div 2] := t;
        t2 := w[i];
        w[i] := w[i div 2];
        w[i div 2] := t2;
        i := i div 2;
      end else break;
  end;
  
  
procedure work;
  var
    i, j, k: longint;
  begin
    m := 0;
    n := 4 * n;
    for i := 1 to n do
      if i<>first then begin
        inc(m);
        p[m] := i;
        w[m] := a[first,i];
      end;
    for i := m div 2 downto 1 do ad_just(i);
    dis[first] := 0;
    for k := 1 to n-1 do begin
      j := p[1];
      dis[j] := w[1];
      if j=last then break;
      w[1] := w[m];
      p[1] := p[m];
      dec(m);
      ad_just(1);
      for i := 1 to m do
        if w[i]>dis[j] + a[j,p[i]] then begin
          w[i] := dis[j] + a[j,p[i]];
          ad_just2(i);
        end;
    end;
  end;


  
begin
  readln(n, per, first, last);
  init;
  work;
  writeln(dis[last]:0:2);
end.
          
