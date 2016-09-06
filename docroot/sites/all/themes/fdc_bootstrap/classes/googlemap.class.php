<?php
class GoogleMap {
	var $canvasId;
	var $centerLatitude;
	var $centerLongitude;
	var $zoom;
	var $zoomUpdateBasedOnRadiusOfCircle;
	var $canvasWidth;
	var $canvasHeight;
	
	// Marker
	var $markers;
	var $markerOptionDefaultAnimation;
	var $markerOptionDefaultIcon;
	var $infoWindowOptionDefaultMaxWidth;
	
	// Circle
	var $circles;
	var $cicleOptionDefaultStrokeColor;
	var $cicleOptionDefaultStrokeOpacity;
	var $cicleOptionDefaultStrokeWeight;
	var $cicleOptionDefaultFillColor;
	var $cicleOptionDefaultFillOpacity;
	
	
	function __construct($centerLatitude = NULL, $centerLongitude = NULL) {
		// General settings
		$this->canvasId = 'googleMapCanvas';
		$this->zoom = 9;
		$this->zoomUpdateBasedOnRadiusOfCircle = FALSE;
		
		// Center
		if (is_numeric($centerLatitude)) {
			$this->centerLatitude = $centerLatitude;
		}
		if (is_numeric($centerLongitude)) {
			$this->centerLongitude = $centerLongitude;
		}
		
		// Size settings
		$this->canvasWidth = '300px';
		$this->canvasHeight = '300px';
		
		// Marker settings
		$this->markers = array();
		$this->markerOptionDefaultAnimation = 'DROP';
		$this->markerOptionDefaultIcon = NULL;
		$this->infoWindowOptionDefaultMaxWidth = 400;
		
		// Circle settings
		$this->circles = array();
		$this->cicleOptionDefaultStrokeColor = '#FF0000';
		$this->cicleOptionDefaultStrokeOpacity = 0.7;
		$this->cicleOptionDefaultStrokeWeight = 2;
		$this->cicleOptionDefaultFillColor = '#FF0000';
		$this->cicleOptionDefaultFillOpacity = 0.25;
		
	}
	
	public function addMarker($latitude, $longitude, $info = NULL, $title = NULL, $id = NULL, $animation = 'DROP', $icon = NULL) {
		$this->markers[$id] = array(
			'latitude' => $latitude,
			'longitude' => $longitude,
			'info' => str_replace(array("\r", "\n"), '', str_replace("'", "\'", $info)),
			'title' => $title,
			'id' => $id,
			'animation' => $animation,
			'icon' => $icon
		);
		return TRUE;
	}
	
	public function addCircle($latitude, $longitude, $size, $id = NULL) {
		$this->circles[] = array(
			'latitude' => $latitude,
			'longitude' => $longitude,
			'size' => $size,
			'id' => $id,
			);
		return TRUE;
	}
	
	public function returnOptionsJs($optionsArr) {
		$optionsSize = sizeof($optionsArr);
		$optionJs = '';
		$i = 1;
		foreach($optionsArr as $option) {
			$optionJs .= $option;
			if ($i != $optionsSize) {$optionJs .= ',';}
			$i++;
		}
		return $optionJs;
	}
	
	public function returnMarkersJs() {
		if ($this->markers) {
			$markersJs = '';
			foreach($this->markers as $marker) {
				
				// Options
				$optionsArr = array(
					'position: new google.maps.LatLng('. $marker['latitude'] .', '. $marker['longitude'] .')',
					'map: map',
				);
				if ($marker['animation']) {$optionsArr[] = 'animation: google.maps.Animation.' . strtoupper($marker['animation']);}
				if (!$marker['animation'] && $this->markerOptionDefaultAnimation) {$optionsArr[] = 'animation: google.maps.Animation.' . strtoupper($this->markerOptionDefaultAnimation);}
				if ($marker['title']) {$optionsArr[] = 'title:"' . $marker['title'] . '"';}
				if ($marker['icon']) {$optionsArr[] = 'icon: "' . $marker['icon'] . '"';}
				if (!$marker['icon'] && $this->markerOptionDefaultIcon) {$optionsArr[] = 'icon: "' . $this->markerOptionDefaultIcon . '"';}
				
				// Set options
				$markerOptionsJs = $this->returnOptionsJs($optionsArr);
				$markersJs .= 'var marker' . $marker['id'] . ' = new google.maps.Marker({' . $markerOptionsJs . '});' . "\n";

				
				// Info window
				if ($marker['info']) {
					$markersJs .= 'var marker' . $marker['id'] . 'Info = \'' . str_replace("'", "\\'", $marker['info']) . '\';
						var marker' . $marker['id'] . 'InfoWindow = new google.maps.InfoWindow({
							content: marker' . $marker['id'] . 'Info,
							maxWidth: ' . $this->infoWindowOptionDefaultMaxWidth . '
						});
						google.maps.event.addListener(marker' . $marker['id'] . ', \'click\', function() {
							if (openInfoWindow) {openInfoWindow.close();}
							marker' . $marker['id'] . 'InfoWindow.open(map,marker' . $marker['id'] . ');
							openInfoWindow = marker' . $marker['id'] . 'InfoWindow;
						});
						';
				}
				$markersJs .= 'var openInfoWindow = \'\';';
			}
		} else {
			$markersJs = NULL;
		}
		return $markersJs;
	}
	
	public function returnCirclesJs() {
		if ($this->circles) {
			foreach($this->circles as $circle) {
				$optionsArr = array(
					'map: map',
					'center: new google.maps.LatLng(' . $circle['latitude'] . ', ' . $circle['longitude'] . ')',
					'radius: ' . (int)$circle['size']
				);
				
				// Stroke color
				if ($cirle['strokeColor']) {
					$optionsArr[] = 'strokeColor: "' . $cirle['strokeColor'] . '"';
				} else {
					$optionsArr[] = 'strokeColor: "' . $this->cicleOptionDefaultStrokeColor . '"';
				}
				// Stroke opacity
				if ($circle['strokeOpacity']) {
					$optionsArr[] = 'strokeOpacity: ' . $circle['strokeOpacity'];
				} else {
					$optionsArr[] = 'strokeOpacity: ' . $this->cicleOptionDefaultStrokeOpacity;
				}
				// Stroke weight
				if ($circle['strokeWeight']) {
					$optionsArr[] = 'strokeWeight: ' . $circle['strokeWeight'];
				} else {
					$optionsArr[] = 'strokeWeight: ' . $this->cicleOptionDefaultStrokeWeight;
				}
				// Fill color
				if ($circle['fillColor']) {
					$optionsArr[] = 'fillColor: "' . $circle['fillColor'] . '"';
				} else {
					$optionsArr[] = 'fillColor: "' . $this->cicleOptionDefaultFillColor . '"';
				}
				// Fill opacity
				if ($circle['fillOpacity']) {
					$optionsArr[] = 'fillOpacity: ' . $circle['fillOpacity'];
				} else {
					$optionsArr[] = 'fillOpacity: ' . $this->cicleOptionDefaultFillOpacity;
				}
				
				$circleOptionsJs = $this->returnOptionsJs($optionsArr);
				
				$circlesJs .= 'circle = new google.maps.Circle({' . $circleOptionsJs . '});' . "\n";
			}
		} else {
			$circlesJs = NULL;
		}
		return $circlesJs;
	}
	
	public function updateZoom() {
		if ($this->zoomUpdateBasedOnRadiusOfCircle) {
			if (sizeof($this->circles) == 1) {
				if ($this->circles[0]['size'] <= 5000) {
					$this->zoom = 12;
				}
				if ($this->circles[0]['size'] > 5000 && $this->circles[0]['size'] <= 10000) {
					$this->zoom = 11;
				}
				if ($this->circles[0]['size'] > 10000 && $this->circles[0]['size'] <= 20000) {
					$this->zoom = 10;
				}
				if ($this->circles[0]['size'] > 20000 && $this->circles[0]['size'] <= 40000) {
					$this->zoom = 9;
				}
				if ($this->circles[0]['size'] > 40000 && $this->circles[0]['size'] <= 80000) {
					$this->zoom = 8;
				}
				if ($this->circles[0]['size'] > 80000 && $this->circles[0]['size'] <= 160000) {
					$this->zoom = 7;
				}
				if ($this->circles[0]['size'] > 160000 && $this->circles[0]['size'] <= 320000) {
					$this->zoom = 6;
				}
			}
		}
	}
	
	public function display() {
		if (!$this->centerLatitude || !$this->centerLongitude) {
			return FALSE;
		}
		// Generate markers
		$markersJs = $this->returnMarkersJs();
		
		// Generate circles
		$circlesJs = $this->returnCirclesJs();
		
		// Update zoom
		$this->updateZoom();
		
		// Generate initialize
		$googleMapHtml = '
		<script type="text/javascript"
									src="http://maps.google.com/maps/api/js?">

		</script>
		<script type="text/javascript">
			function initialize() {
				var latlng = new google.maps.LatLng(' . $this->centerLatitude . ', ' . $this->centerLongitude . ');
				var myOptions = {
					zoom: ' . $this->zoom . ',
					center: latlng,
					mapTypeId: google.maps.MapTypeId.ROADMAP
				};
				var map = new google.maps.Map(document.getElementById("' . $this->canvasId . '"),myOptions);
				' . $markersJs . '
				' . $circlesJs . '
			}
		</script>
		<div id="googleMapCanvas" style="width: ' . $this->canvasWidth . '; height: ' . $this->canvasHeight . ';"></div>
		<script type="text/javascript">
			jQuery(document).ready(function(){
				initialize();
			});
		</script>
			';
		return $googleMapHtml;
	}
}
