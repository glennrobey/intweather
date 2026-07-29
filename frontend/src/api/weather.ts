import { useEffect, useState } from "react";
import { getWeather, getCitySuggestions } from "./api/weather";
import WeatherCard from "./components/WeatherCard";
import SearchBar from "./components/SearchBar";
import type { Weather } from "./types/Weather";

export interface Weather {
  city: string;
  temperatureF: number;
  feelsLikeF: number;
  humidity: number;
  windSpeedMph: number;
  condition: string;
}

export async function getWeather(city: string) {
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
