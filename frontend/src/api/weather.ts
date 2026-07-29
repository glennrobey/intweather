export interface Weather {
  city: string;
  temperatureF: number;
  feelsLikeF: number;
  humidity: number;
  windSpeedMph: number;
  condition: string;
}

export async function getWeather(city: string) {
  const response = await fetch(
    `http://localhost:8080/api/weather?city=${encodeURIComponent(city)}`,
  );

  console.log("Status:", response.status);

  const text = await response.text();

  console.log("Backend response:", text);

  if (!response.ok) {
    throw new Error("Failed to fetch weather");
  }

  return JSON.parse(text);
}

export async function getCitySuggestions(query: string): Promise<string[]> {
  const response = await fetch(
    `http://localhost:8080/api/cities?query=${encodeURIComponent(query)}`,
  );

  if (!response.ok) {
    throw new Error("Failed to fetch city suggestions");
  }

  return response.json();
}
