import type { Weather } from "../types/Weather";

export async function getWeather(city: string): Promise<Weather> {
  const API_URL = import.meta.env.VITE_API_URL;

  const response = await fetch(
    `${API_URL}/api/weather?city=${encodeURIComponent(city)}`,
  );

  if (!response.ok) {
    throw new Error("Failed to fetch weather");
  }

  return response.json();
}

export async function getCitySuggestions(query: string): Promise<string[]> {
  const API_URL = import.meta.env.VITE_API_URL;

  const response = await fetch(
    `${API_URL}/api/cities?query=${encodeURIComponent(query)}`,
  );

  if (!response.ok) {
    throw new Error("Failed to fetch city suggestions");
  }

  return response.json();
}
