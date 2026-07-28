export interface Weather {
  city: string;
  feelsLikeF: number;
  humidity: number;
  windSpeedMph: number;
  condition: string;
}

export async function getWeather(city: string): Promise<Weather> {
  const response = await fetch(
    `http://localhost:8080/api/weather?city=${city}`,
  );

  if (!response.ok) {
    throw new Error("Failed to fetch weather");
  }

  return response.json();
}
