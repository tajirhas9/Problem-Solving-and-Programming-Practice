while(left <= right) {
		if(leftCheck) {
			if(ft) {
				if(w[left] * l == w[right] * r) {
					if(w[left+1] * l >= w[right] * r) {
						ans1 += w[left] * l;
						left++;
						leftCheck = true;
					}
					else {
						ans1 += w[right] * r;
						right--;
						leftCheck = false;
					}
				}
				else {
					if(w[left] * l < w[right] * r) {
						ans1 += w[left] * l;
						left++;
						leftCheck = true;
					}
					else {
						ans1 += w[right] * r;
						right--;
						leftCheck = false;
					}
				}

				ft = !ft;
				dbg(ans1);
				continue;
			}
			if( (w[left] * l + ql) < w[right] * r ) {
				ans1 += (w[left] * l + ql);
				left++;
			}
			else {
				ans1 += (w[right] * r);
				right--;
				leftCheck = !leftCheck;
			}
		}
		else {
			if( (w[right] * r + qr) < w[left] * l ) {
				ans1 += (w[right] * r + qr);
				right--;
			} 
			else {
				ans1 += (w[left] * l);
				left++;
				leftCheck = !leftCheck;
			}
		}
		dbg(ans1);
	}